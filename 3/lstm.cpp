#include <iostream>
#include <cmath>
#include <vector>
#include <functional>
#include <numeric>

class LSTMCell {
public:
    LSTMCell(int input_size, int hidden_size) 
        : input_size(input_size), hidden_size(hidden_size) {
        // Initialize weights and biases
        W_i = initialize_matrix(hidden_size, input_size);
        W_f = initialize_matrix(hidden_size, input_size);
        W_c = initialize_matrix(hidden_size, input_size);
        W_o = initialize_matrix(hidden_size, input_size);

        U_i = initialize_matrix(hidden_size, hidden_size);
        U_f = initialize_matrix(hidden_size, hidden_size);
        U_c = initialize_matrix(hidden_size, hidden_size);
        U_o = initialize_matrix(hidden_size, hidden_size);

        b_i = initialize_vector(hidden_size);
        b_f = initialize_vector(hidden_size);
        b_c = initialize_vector(hidden_size);
        b_o = initialize_vector(hidden_size);
    }

    std::vector<double> forward(const std::vector<double>& input, const std::vector<double>& prev_hidden_state, const std::vector<double>& prev_cell_state) {
        // Compute input, forget, cell, and output gates
        std::vector<double> i = sigmoid(add(multiply(W_i, input), multiply(U_i, prev_hidden_state), b_i));
        std::vector<double> f = sigmoid(add(multiply(W_f, input), multiply(U_f, prev_hidden_state), b_f));
        std::vector<double> c_tilde = tanh1(add(multiply(W_c, input), multiply(U_c, prev_hidden_state), b_c));
        std::vector<double> o = sigmoid(add(multiply(W_o, input), multiply(U_o, prev_hidden_state), b_o));

        // Update cell state and hidden state
        cell_state = add(multiply(f, prev_cell_state), multiply(i, c_tilde));
        hidden_state = multiply(o, tanh1(cell_state));

        return hidden_state;
    }

     void backward(const std::vector<double>& input, const std::vector<double>& prev_hidden_state,
                  const std::vector<double>& prev_cell_state, const std::vector<double>& d_hidden_state) {
        // Compute gradients for each parameter
        std::vector<double> d_o = multiply(d_hidden_state, tanh1(cell_state));
        std::vector<double> d_c_tilde = multiply(d_hidden_state, multiply(d_o, dtanh(tanh1(cell_state))));
        std::vector<double> d_i = multiply(d_c_tilde, d_c_tilde);
        std::vector<double> d_f = multiply(d_c_tilde, prev_cell_state);
        std::vector<double> d_c = multiply(d_c_tilde, d_f);

        // Update gradients for biases
        db_o = d_o;
        db_c = d_c_tilde;
        db_i = d_i;
        db_f = d_f;

        // Update gradients for weights
        dW_o = outer_product(d_o, input);
        dW_c = outer_product(d_c_tilde, input);
        dW_i = outer_product(d_i, input);
        dW_f = outer_product(d_f, input);

        // Update gradients for hidden state weights
        dU_o = outer_product(d_o, prev_hidden_state);
        dU_c = outer_product(d_c_tilde, prev_hidden_state);
        dU_i = outer_product(d_i, prev_hidden_state);
        dU_f = outer_product(d_f, prev_hidden_state);
        d_input = add(add(add(multiply(dU_i, d_i), multiply(dU_f, d_f)), multiply(dU_c, d_c_tilde)), multiply(dU_o, d_o));
    }

    // Apply gradient descent to update parameters
    void update_parameters(double learning_rate) {
        // Update biases
        b_o = subtract(b_o, multiply_scalar(db_o, learning_rate));
        b_c = subtract(b_c, multiply_scalar(db_c, learning_rate));
        b_i = subtract(b_i, multiply_scalar(db_i, learning_rate));
        b_f = subtract(b_f, multiply_scalar(db_f, learning_rate));

        // Update weights
        W_o = subtract(W_o, multiply_scalar(dW_o, learning_rate));
        W_c = subtract(W_c, multiply_scalar(dW_c, learning_rate));
        W_i = subtract(W_i, multiply_scalar(dW_i, learning_rate));
        W_f = subtract(W_f, multiply_scalar(dW_f, learning_rate));

        // Update hidden state weights
        U_o = subtract(U_o, multiply_scalar(dU_o, learning_rate));
        U_c = subtract(U_c, multiply_scalar(dU_c, learning_rate));
        U_i = subtract(U_i, multiply_scalar(dU_i, learning_rate));
        U_f = subtract(U_f, multiply_scalar(dU_f, learning_rate));
    }

    std::vector<double> get_hidden_state()
    {
        return hidden_state;
    }

    std::vector<double> get_cell_state()
    {
        return cell_state;
    }

    std::vector<double> get_d_input()
    {
        return d_input;
    }

     std::vector<double> get_d_input() const {
        // Return the gradient of the loss with respect to the input
        return d_input;
    }

private:
    int input_size;
    int hidden_size;

    std::vector<double> W_i, W_f, W_c, W_o;
    std::vector<double> U_i, U_f, U_c, U_o;
    std::vector<double> b_i, b_f, b_c, b_o;

    std::vector<double> cell_state, hidden_state;
    std::vector<double> d_input; 

    std::vector<double> db_o, db_c, db_i, db_f;  // Gradients for biases
    std::vector<double> dW_o, dW_c, dW_i, dW_f;  // Gradients for weights
    std::vector<double> dU_o, dU_c, dU_i, dU_f;  // Gradients for hidden state weights

    // Helper functions for element-wise operations
    std::vector<double> subtract(const std::vector<double>& a, const std::vector<double>& b) {
        std::vector<double> result;
        for (int i = 0; i < a.size(); ++i) {
            result.push_back(a[i] - b[i]);
        }
        return result;
    }

    std::vector<double> multiply_scalar(const std::vector<double>& a, double scalar) {
        std::vector<double> result;
        for (const auto& value : a) {
            result.push_back(value * scalar);
        }
        return result;
    }

    std::vector<double> outer_product(const std::vector<double>& a, const std::vector<double>& b) {
        std::vector<double> result;
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < b.size(); ++j) {
                result.push_back(a[i] * b[j]);
            }
        }
        return result;
    }

    std::vector<double> dtanh(const std::vector<double>& x) {
        std::vector<double> result;
        for (const auto& value : x) {
            result.push_back(1.0 - std::pow(tanh(value), 2));
        }
        return result;
    }
    std::vector<double> initialize_matrix(int rows, int cols) {
        // Initialize weights with small random values
        std::vector<double> matrix;
        for (int i = 0; i < rows * cols; ++i) {
            matrix.push_back((rand() % 1000 - 500) / 1000.0); // Random values between -0.5 and 0.5
        }
        return matrix;
    }

    std::vector<double> initialize_vector(int size) {
        // Initialize biases with small random values
        std::vector<double> vector;
        for (int i = 0; i < size; ++i) {
            vector.push_back((rand() % 1000 - 500) / 1000.0); // Random values between -0.5 and 0.5
        }
        return vector;
    }

    std::vector<double> sigmoid(const std::vector<double>& x) {
        std::vector<double> result;
        for (const auto& value : x) {
            result.push_back(1.0 / (1.0 + exp(-value)));
        }
        return result;
    }

    std::vector<double> tanh1(const std::vector<double>& x) {
        std::vector<double> result;
        for (const auto& value : x) {
            result.push_back(tanh(value));
        }
        return result;
    }

    std::vector<double> add(const std::vector<double>& a, const std::vector<double>& b) {
        std::vector<double> result;
        for (int i = 0; i < a.size(); ++i) {
            result.push_back(a[i] + b[i]);
        }
        return result;
    }

    std::vector<double> add(const std::vector<double>& a, const std::vector<double>& b, const std::vector<double>& c) {
        return add(add(a, b), c);
    }

    std::vector<double> multiply(const std::vector<double>& a, double scalar) {
        std::vector<double> result;
        for (const auto& value : a) {
            result.push_back(value * scalar);
        }
        return result;
    }

    std::vector<double> multiply(const std::vector<double>& a, const std::vector<double>& b) {
        std::vector<double> result;
        for (int i = 0; i < a.size(); ++i) {
            result.push_back(a[i] * b[i]);
        }
        return result;
    }
};


#include <iostream>
#include <vector>
#include <cmath>

class LSTMLayer {
public:
    LSTMLayer(int input_size, int hidden_size, int num_layers)
        : input_size(input_size), hidden_size(hidden_size), num_layers(num_layers) {
        for (int i = 0; i < num_layers; ++i) {
            lstm_cells.push_back(LSTMCell(input_size, hidden_size));
        }
    }

    std::vector<double> forward(const std::vector<double>& input) {
        std::vector<double> current_input = input;

        for (int i = 0; i < num_layers; ++i) {
            current_input = lstm_cells[i].forward(current_input, hidden_states[i], cell_states[i]);
            hidden_states[i] = lstm_cells[i].get_hidden_state();
            cell_states[i] = lstm_cells[i].get_cell_state();
        }

        return current_input;  // Output of the last layer
    }

    void backward(const std::vector<double>& input, const std::vector<double>& target_output) {
        std::vector<double> d_hidden_state(hidden_size, 1.0);

        for (int i = num_layers - 1; i >= 0; --i) {
            lstm_cells[i].backward(input, hidden_states[i - 1], cell_states[i - 1], d_hidden_state);
            d_hidden_state = lstm_cells[i].get_d_input();
            lstm_cells[i].update_parameters(0.01); // Learning rate: 0.01
        }
    }

private:
    int input_size;
    int hidden_size;
    int num_layers;

    std::vector<LSTMCell> lstm_cells;
    std::vector<std::vector<double>> hidden_states;  // Hidden states for each layer
    std::vector<std::vector<double>> cell_states;    // Cell states for each layer
};

int main() {
    const int input_size = 3;
    const int hidden_size = 4;
    const int num_layers = 2;

    LSTMLayer lstm_layer(input_size, hidden_size, num_layers);

    // Example input and target output (for demonstration purposes)
    std::vector<double> input = {0.1, 0.2, 0.3};
    std::vector<double> target_output = {0.1, 0.2, 0.3, 0.4};

    // Forward pass through the LSTM layer
    std::vector<double> output = lstm_layer.forward(input);

    // Compute loss (for demonstration purposes)
    double loss = 0.5 * std::inner_product(output.begin(), output.end(), output.begin(), 0.0) -
                  std::inner_product(output.begin(), output.end(), target_output.begin(), 0.0);

    // Backward pass and update parameters
    lstm_layer.backward(input, target_output);

    return 0;
}

/*

int main() {
      const int input_size = 3;
    const int hidden_size = 4;

    LSTMCell lstm_cell(input_size, hidden_size);

    // Example input, previous hidden state, and previous cell state
    std::vector<double> input = {0.1, 0.2, 0.3};
    std::vector<double> prev_hidden_state = {0.4, 0.5, 0.6, 0.7};
    std::vector<double> prev_cell_state = {0.8, 0.9, 1.0, 1.1};

    // Forward pass through the LSTM cell
    std::vector<double> output = lstm_cell.forward(input, prev_hidden_state, prev_cell_state);

    // Example target output (for demonstration purposes)
    std::vector<double> target_output = {0.1, 0.2, 0.3, 0.4};

    // Compute loss (for demonstration purposes)
    double loss = 0.5 * std::inner_product(output.begin(), output.end(), output.begin(), 0.0) -
                  std::inner_product(output.begin(), output.end(), target_output.begin(), 0.0);
    std::cout<<"loss:"<<loss <<std::endl;
    // Backward pass and update parameters
    std::vector<double> d_hidden_state(hidden_size, 1.0);
    lstm_cell.backward(input, prev_hidden_state, prev_cell_state, d_hidden_state);
    lstm_cell.update_parameters(0.01); // Learning rate: 0.01

    return 0;
}
*/