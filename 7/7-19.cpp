int main()
{ 
    int boys=4, girls=3; 
    auto totalChild=[girls,&boys]()->int{return girls+boys;}; 
    return totalChild(); 
}