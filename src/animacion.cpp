#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include <Dibujo.hpp>
#include <GestorDibujos.hpp>
//#include <Corral.hpp>
using namespace ftxui;
int main()
{
    auto screen = Screen::Create(
        Dimension::Fixed(100),
        Dimension::Fixed(20));

    const std::vector<std::u32string> nota1 ={
        U"  , ",
        U"  | ",
        U" 0' ",};

    const std::vector<std::u32string> nota2 ={
        U" , ",
        U" |)",
        U"0' "};

    const std::vector<std::u32string> nota3 = {
        U"  ____ ",  
        U"  |  | ",  
        U" 0' 0' "};

    const std::vector<std::u32string> instrumento = {                               
        U"    _,,._                        ",
        U"  ,'     `.__,--.                ",
        U" /   .--.        |           ,,, ",
        U" | [=========|==|==|=|==|=|==___]",
        U" !   '--'  __    |           ''' ",
        U"  `._   _,'  `--'                ",
        U"     ""'                         "};

    GestorDibujos gestor;

    gestor.Agregar(Dibujo(49, 8, nota1, ftxui::Color::DarkRed));
    gestor.Agregar(Dibujo(53, 7, nota1, ftxui::Color::DarkRed));
    gestor.Agregar(Dibujo(57, 8, nota1, ftxui::Color::DarkRed));
    gestor.Agregar(Dibujo(61, 7, nota1, ftxui::Color::DarkRed));

    gestor.Agregar(Dibujo(35, 5, nota2, ftxui::Color::DarkGreen));
    gestor.Agregar(Dibujo(39, 4, nota2, ftxui::Color::DarkGreen));
    gestor.Agregar(Dibujo(44, 5, nota2, ftxui::Color::DarkGreen));
    gestor.Agregar(Dibujo(48, 4, nota2, ftxui::Color::DarkGreen));

    gestor.Agregar(Dibujo(30, 10, nota3, ftxui::Color::DarkBlue));
    gestor.Agregar(Dibujo(36, 12, nota3, ftxui::Color::DarkBlue));
    gestor.Agregar(Dibujo(42, 10, nota3, ftxui::Color::DarkBlue));
    gestor.Agregar(Dibujo(48, 12, nota3, ftxui::Color::DarkBlue));

    gestor.Agregar(Dibujo(10, 6, instrumento, ftxui::Color::SandyBrown));


    int frames = 120;
    for (int frame = 0; frame < frames; ++frame)
    {
        screen.Clear();
        /*notas rojas x*/
        gestor.dibujos[0].x = 49 + (frame % 15);

        gestor.dibujos[1].x = 53 + (frame % 15);

        gestor.dibujos[2].x = 57 + (frame % 15);

        gestor.dibujos[3].x = 61 + (frame % 15);
        /*notas verdes x*/
        gestor.dibujos[4].x = 35 + (frame % 15);

        gestor.dibujos[5].x = 39 + (frame % 15);

        gestor.dibujos[6].x = 44 + (frame % 15);

        gestor.dibujos[7].x = 48 + (frame % 15);
        /*notas moradas x*/
        gestor.dibujos[8].x = 30 + (frame % 15);

        gestor.dibujos[9].x = 36 + (frame % 15);

        gestor.dibujos[10].x = 42 + (frame % 15);

        gestor.dibujos[11].x = 48 + (frame % 15);

        /**/ 

        /*notas rojas y*/
        gestor.dibujos[0].y = 8 + (frame % 2);

        gestor.dibujos[1].y = 7 + (frame % 2);

        gestor.dibujos[2].y = 8 + (frame % 2);

        gestor.dibujos[3].y = 7 + (frame % 2);
        /*notas verdes y*/
        gestor.dibujos[4].y = 5 + (frame % 2);

        gestor.dibujos[5].y = 4 + (frame % 2);

        gestor.dibujos[6].y = 5 + (frame % 2);

        gestor.dibujos[7].y = 4 + (frame % 2);
        /*notas moradas y*/
        gestor.dibujos[8].y = 10 + (frame % 2);

        gestor.dibujos[9].y = 12 + (frame % 2);

        gestor.dibujos[10].y = 10 + (frame % 2);

        gestor.dibujos[11].y = 12 + (frame % 2);

        gestor.DibujarTodos(screen);


        std::cout << screen.ToString();
        std::cout << screen.ResetPosition();
        std::cout << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(500)); 
        
    }
    return 0;
}
