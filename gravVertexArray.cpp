#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <thread>
#include <ctime>
using namespace std;
using namespace sf;
using namespace std::this_thread; 
using namespace std::chrono_literals; 

int main()
{
    unsigned int ResX = 800;
    unsigned int ResY = 800;


    float x = 0;
    float y = 0;
    double zacatek = 0;
    double rozdil = 0.1;
    double sinus;
    float PosX = 0;
    float PosY = ResY / 2;

    float Amp;
    float Perioda;
    float PosunX;
    float PosunY;
    float sirka;
    float sklon;
    float mocnina;
    float ampexp;
    string GOONfunkce;
    string funkce;
    string zacitznovu;
    bool kvafce = false;
    bool gonfce = false;
    bool linfce = false;
    bool expfce = false;

    float prevX = 0;
    float prevY = 0;
    bool firstPoint = true;

   // Font font;
   // font.openFromFile("KelveticaNobis-A5z6.ttf");

while(true){

    while (true)
    {
        cout << "vítejte v grafickém kalkulátoru chcete kreslid Goniometrické funkce nebo kvadraticke, lineární (gon / moc / exp ) : ";
        cin >> funkce;
   
        if (funkce == "gon")
            {
            cout << "napište funkci ve tvaru (Amplituda funkce(sin tg cos cotg) (2 pí)/perioda posunX posunY)(př.: 200 sin 200 0 0) : ";
            cin >> Amp >>  GOONfunkce >> Perioda >> PosunX >> PosunY;
            gonfce = true;
            break;
            } else if (funkce == "moc")
                {
                   cout << "Napište mocninou funkci ve tvaru (Amp šířka mocnina posunX posunY)(př.: 1 0.05 2 200 100) : ";
                   cin >> Amp >> sirka >> mocnina >> PosunX >> PosunY;
                   kvafce = true;
                   break;
                } else if (funkce == "lin")
                    {
                    cout << "Napište kvadratickou funkci ve tvaru (sklon posunX posunY) : ";
                    cin >> sklon >> PosunX >> PosunY;
                    linfce = true;
                    break;
                    } else if (funkce == "exp")
                        {
                            cout << "Napište exponenciální funkci ve tvaru (Amp AmpExp posunX posunY)(př.: 1 1.05 200 100): ";
                            cin >> Amp >> ampexp >> PosunX >> PosunY;
                            expfce = true;
                            break;
                        } else {
                            cout << "!!! Typ funkce není zapsán ve správném tvaru !!!" << "\n";
                        }
                    
                    
                    
                    
                    
    }

    vector<sf::Vertex> body;

    RectangleShape osaX({ResX, 1});
    osaX.setOrigin({ResX/2, 0.5});
    osaX.setPosition({ResX/2, ResY/2});
    osaX.setFillColor(Color::Cyan);

    RectangleShape osaY({1, ResY});
    osaY.setOrigin({0.5, ResY/2});
    osaY.setPosition({ResX/2, ResY/2});
    osaY.setFillColor(Color::Cyan);

    ContextSettings settings;
    settings.antiAliasingLevel = 8;

    RenderWindow okno(VideoMode({ResX, ResY}), "grafiik");
    
    while (okno.isOpen())
    {
        while (const optional event = okno.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) {
              okno.close(); 
              break; 
            }
        }

            
                    float ysin = Amp * sin(((2* M_PI) / Perioda) * zacatek - PosunX) + (PosY - PosunY);
                    float ytg = Amp * tan(((2* M_PI) / Perioda) * zacatek - PosunX) + (PosY - PosunY);
                    float ycos = Amp * cos(((2* M_PI) / Perioda) * zacatek - PosunX) + (PosY - PosunY);
                    float ykva = -Amp * pow(sirka * (zacatek - (ResX/2) - PosunX), mocnina) + ((ResY/2) + PosunY);
                    //float ykva = -1*pow(0.5 * (zacatek - 600), 2) + 400;        
                    //float ylin = -1 * Amp * (zacatek - ((ResX/2) - PosunX)) + ((ResY/2) + PosunY);
                    float ylin = -3*(zacatek - 600-200)+400;
                    //float ylin = -Amp * pow(zacatek - (ResX/2) - PosunX, 1) + ((ResY/2) + PosunY);
                    //float yexp = -1 * pow(1.05, zacatek - 600) + 400;
                    float yexp = -Amp * pow(ampexp, (zacatek - (ResX/2)- PosunX)) + (ResY/2) +PosunY;


                if (GOONfunkce == "sin")
                    {
                        ytg = 0;
                        ycos = 0;
                        ykva = 0;
                        ylin = 0;
                        yexp = 0;
                    } else if (GOONfunkce == "tg")
                        {
                            ysin = 0;
                            ycos = 0;
                            ykva = 0;
                            ylin = 0; 
                            yexp = 0;
                        } else if (GOONfunkce == "cos")
                            {
                                ysin = 0;
                                ytg = 0;
                                ykva = 0; 
                                ylin = 0;
                                yexp = 0;
                            } else if (kvafce == true)
                                {
                                    ysin = 0;
                                    ycos = 0;
                                    ytg = 0;
                                    ylin = 0;
                                    yexp = 0;
                                } else if (linfce == true)
                                    {
                                        ysin = 0;
                                        ycos = 0;
                                        ytg = 0;
                                        ykva = 0;
                                        yexp = 0;
                                    } else if (expfce == true)
                                    {
                                        ysin = 0;
                                        ycos = 0;
                                        ytg = 0;
                                        ykva = 0;
                                        ylin = 0;
                                    } else{
                                            cout << "Funkce nebyla správně zadaná";
                                            okno.close();

                                        } 
                                    
                                    
                                    
                                    

            zacatek = zacatek + rozdil;    
            float y = ysin + ytg + ycos + ykva + ylin + yexp;
            float x = zacatek;
            int pocet = 0;
            float prusecikY = -1 * (y - (ResY/2)); 
            float prusecikX = 1 * (zacatek - (ResX/2)) - rozdil;

            //cout << y << "\n";


            CircleShape bod(5.f);
            bod.setOrigin({5.f, 5.f});
            bod.setPosition({x, y});
            bod.setFillColor(Color::Red);

            body.emplace_back(sf::Vertex{sf::Vector2f(x, y), sf::Color::White});

            if (abs(zacatek - ResX/2) == (rozdil * 1))
            {
                cout << "průsečík s osou Y je : " << prusecikY << "\n";
            }

            if (abs((y-ResY/2)) == 0.1)
            {
                cout << "průsečík s osou X je : " << prusecikX << "\n";
            }

            if (zacatek >= ResX)
            {
                zacatek = 0;
                body.clear();
            }

        okno.clear(Color::Black);

        if (!body.empty()){
            okno.draw(body.data(), body.size(), sf::PrimitiveType::Points);
        }
        okno.draw(bod);
        okno.draw(osaX);
        okno.draw(osaY);
        okno.display();

    }
    cout << "chcete jít zpět (y/n)? ";
    cin >> zacitznovu;
    if (zacitznovu == "n")
    {
        break;
    }
    

}

}