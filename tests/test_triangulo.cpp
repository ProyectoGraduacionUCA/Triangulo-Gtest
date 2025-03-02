#include <gtest/gtest.h>
#include <sstream>
#include "../triangulo.cpp"

TEST(TrianguloTest, OutputCorrecto) {
    std::stringstream input("2\n4\n5\n");
    std::stringstream output;
    std::streambuf* cin_backup = std::cin.rdbuf();
    std::streambuf* cout_backup = std::cout.rdbuf();
    
    std::cin.rdbuf(input.rdbuf());
    std::cout.rdbuf(output.rdbuf());

    main();  // Llamamos a la función principal del estudiante

    std::cin.rdbuf(cin_backup);
    std::cout.rdbuf(cout_backup);

    std::string expected = 
        "*\n"
        "**\n"
        "*\n"
        "**\n"
        "***\n"
        "****\n"
        "*\n"
        "**\n"
        "***\n"
        "****\n"
        "*****\n";

    EXPECT_EQ(output.str(), expected);
}
