#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
int main(int argc, char ** argv){
    bool opposite=false;
    bool quit=false,keydown=false;
    bool goal_bool=false;
    bool same_direction=false;
    bool first_click_player1=false,first_click_player2=false;
    //bool nobat=false; //true: darvazeban , false: mohajem
    bool quit_info=false,quit_menu=false,quit_aboutus=false,quit_infos_team,quit_all=false;
    int x_ball=370,y_ball=320,fx,fy,sh=0,h=1,aa=75,a=0,bx,by,x_chap,y_chap,number=0,number2=0;
    bool first_click_read=false;
    int menu=1;
    bool quit_teams = false;
    //int turn=0;
    int choose_team = 0,choose_team_2 = 0;
    int x_gk=345,y_gk=200;
    int x1,y1,x_team,y_team,x_menu,y_menu,x_menu2,y_menu2;
    int goalkeeper_pos;
    int gk_num;
    int mouse_pos,gk_pos=0;
    int voice=1;
    int results[10];
    for (int i=0;i<10;i++) results[i]=0;
    #define print std::cout<<
    #define newline print"\n";
    SDL_Event menu_event,info_event,e,teams_event,saver;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window * window = SDL_CreateWindow("Football",460, 250, 800, 400, 0);
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface * backpic = IMG_Load("goal.png");
    SDL_Surface * goals[4] = {IMG_Load("redgoal.png"),IMG_Load("bluegoal.png"),IMG_Load("redsave.png"),IMG_Load("bluesave.png")};
    SDL_Surface * balls[5] = { IMG_Load("ball1.png") , IMG_Load("ball2.png") , IMG_Load("ball3.png") , IMG_Load("ball4.png") ,IMG_Load("ball5.png")};
    SDL_Surface * photos[16] = { IMG_Load("chooseteam.png") , IMG_Load("chooseteam2.png") , IMG_Load("C_vs_B.png") , IMG_Load("R_vs_B.png") ,IMG_Load("U_vs_B.png") ,
    IMG_Load("R_vs_C.png") , IMG_Load("U_vs_C.png") , IMG_Load("U_vs_R.png") , IMG_Load("about.png") , IMG_Load("inf.png") , IMG_Load("pg.png") , IMG_Load("scoreboard.png") ,
    IMG_Load("Barcelona_text.png") , IMG_Load("Real_Madrid_text.png") , IMG_Load("Man_City_text.png") , IMG_Load("Man_United_text.png") ,};
    SDL_Surface * team_infos[4] = {IMG_Load("info_bc.png"),IMG_Load("info_rm.png"),IMG_Load("info_mu.png"),IMG_Load("info_mc.png")};
    SDL_Surface * gosa[5] = {IMG_Load("bc_save.png"),IMG_Load("mc_save.png"),IMG_Load("mu_save.png"),IMG_Load("rm_save.png"),IMG_Load("score.png")};
    SDL_Surface * number_goal[6] = {IMG_Load("photo0.png"),IMG_Load("photo1.png"),IMG_Load("photo2.png"),IMG_Load("photo3.png"),IMG_Load("photo4.png"),IMG_Load("photo5.png")};
    SDL_Surface * number_goal2[6] = {IMG_Load("photo02.png"),IMG_Load("photo12.png"),IMG_Load("photo22.png"),IMG_Load("photo32.png"),IMG_Load("photo42.png"),IMG_Load("photo52.png")};
    SDL_Surface * just_text[2] = {IMG_Load("aboutus_text2.png"),IMG_Load("info_text2.png")};
    SDL_Surface * scores[6] = {IMG_Load("B_vs_C_score.png"),IMG_Load("B_vs_R_score.png"),IMG_Load("B_vs_U_score.png"),
    IMG_Load("C_vs_R_score.png"),IMG_Load("C_vs_U.png"),IMG_Load("U_vs_R_score.ong")};
    SDL_Texture * finall_bc = SDL_CreateTextureFromSurface (renderer, scores[0]);
    SDL_Texture * finall_br = SDL_CreateTextureFromSurface (renderer, scores[1]);
    SDL_Texture * finall_bu = SDL_CreateTextureFromSurface (renderer, scores[2]);
    SDL_Texture * finall_cr = SDL_CreateTextureFromSurface (renderer, scores[3]);
    SDL_Texture * finall_cu = SDL_CreateTextureFromSurface (renderer, scores[4]);
    SDL_Texture * finall_ur = SDL_CreateTextureFromSurface (renderer, scores[5]);
    SDL_Texture * aboutus_text_show = SDL_CreateTextureFromSurface (renderer, just_text[0]);
    SDL_Texture * info_text_show = SDL_CreateTextureFromSurface(renderer, just_text[1]);
    SDL_Texture * team_info_bc = SDL_CreateTextureFromSurface (renderer, team_infos[0]);
    SDL_Texture * team_info_rm = SDL_CreateTextureFromSurface (renderer, team_infos[1]);
    SDL_Texture * team_info_mu = SDL_CreateTextureFromSurface (renderer, team_infos[2]);
    SDL_Texture * team_info_mc = SDL_CreateTextureFromSurface (renderer, team_infos[3]);
    SDL_Texture * textureb = SDL_CreateTextureFromSurface(renderer, backpic);
    SDL_Texture * redgoal_show = SDL_CreateTextureFromSurface(renderer, goals[0]);
    SDL_Texture * bluegoal_show = SDL_CreateTextureFromSurface(renderer, goals[1]);
    SDL_Texture * redsave_show = SDL_CreateTextureFromSurface(renderer, goals[2]);
    SDL_Texture * bluesave_show = SDL_CreateTextureFromSurface(renderer, goals[3]);
    SDL_Texture * ball1_show = SDL_CreateTextureFromSurface(renderer, balls[0]);
    SDL_Texture * ball2_show = SDL_CreateTextureFromSurface(renderer, balls[1]);
    SDL_Texture * ball3_show = SDL_CreateTextureFromSurface(renderer, balls[2]);
    SDL_Texture * ball4_show = SDL_CreateTextureFromSurface(renderer, balls[3]);
    SDL_Texture * ball5_show = SDL_CreateTextureFromSurface(renderer, balls[4]);
    SDL_Texture * chooseteam_show = SDL_CreateTextureFromSurface (renderer, photos[0]);
    SDL_Texture * chooseteam2_show = SDL_CreateTextureFromSurface (renderer, photos[1]);
    SDL_Texture * C_vs_B_show = SDL_CreateTextureFromSurface (renderer, photos[2]);
    SDL_Texture * R_vs_B_show = SDL_CreateTextureFromSurface (renderer, photos[3]);
    SDL_Texture * U_vs_B_show = SDL_CreateTextureFromSurface (renderer, photos[4]);
    SDL_Texture * R_vs_C_show = SDL_CreateTextureFromSurface (renderer, photos[5]);
    SDL_Texture * U_vs_C_show = SDL_CreateTextureFromSurface (renderer, photos[6]);
    SDL_Texture * U_vs_R_show = SDL_CreateTextureFromSurface (renderer, photos[7]);
    SDL_Texture * about_show = SDL_CreateTextureFromSurface (renderer, photos[8]);
    SDL_Texture * inf_show = SDL_CreateTextureFromSurface (renderer, photos[9]);
    SDL_Texture * pg_show = SDL_CreateTextureFromSurface (renderer, photos[10]);
    SDL_Texture * scoreboard_show = SDL_CreateTextureFromSurface (renderer, photos[11]);
    SDL_Texture * Barcelona_text_show = SDL_CreateTextureFromSurface (renderer, photos[12]);
    SDL_Texture * Real_Madrid_text_show = SDL_CreateTextureFromSurface (renderer, photos[13]);
    SDL_Texture * Man_City_text_show = SDL_CreateTextureFromSurface (renderer, photos[14]);
    SDL_Texture * Man_United_text_show = SDL_CreateTextureFromSurface (renderer, photos[15]);
    SDL_Texture * bc_save_show = SDL_CreateTextureFromSurface (renderer, gosa[0]);
    SDL_Texture * mc_save_show = SDL_CreateTextureFromSurface (renderer, gosa[1]);
    SDL_Texture * mu_save_show = SDL_CreateTextureFromSurface (renderer, gosa[2]);
    SDL_Texture * rm_save_show = SDL_CreateTextureFromSurface (renderer, gosa[3]);
    SDL_Texture * score_show = SDL_CreateTextureFromSurface (renderer, gosa[4]);
    SDL_Texture * photo0_show = SDL_CreateTextureFromSurface (renderer, number_goal[0]);
    SDL_Texture * photo1_show = SDL_CreateTextureFromSurface (renderer, number_goal[1]);
    SDL_Texture * photo2_show = SDL_CreateTextureFromSurface (renderer, number_goal[2]);
    SDL_Texture * photo3_show = SDL_CreateTextureFromSurface (renderer, number_goal[3]);
    SDL_Texture * photo4_show = SDL_CreateTextureFromSurface (renderer, number_goal[4]);
    SDL_Texture * photo5_show = SDL_CreateTextureFromSurface (renderer, number_goal[5]);
    SDL_Texture * photo02_show = SDL_CreateTextureFromSurface (renderer, number_goal2[0]);
    SDL_Texture * photo12_show = SDL_CreateTextureFromSurface (renderer, number_goal2[1]);
    SDL_Texture * photo22_show = SDL_CreateTextureFromSurface (renderer, number_goal2[2]);
    SDL_Texture * photo32_show = SDL_CreateTextureFromSurface (renderer, number_goal2[3]);
    SDL_Texture * photo42_show = SDL_CreateTextureFromSurface (renderer, number_goal2[4]);
    SDL_Texture * photo52_show = SDL_CreateTextureFromSurface (renderer, number_goal2[5]);
    SDL_Rect photo0 = {5, 7, 20, 35};
    SDL_Rect photo1 = {5, 7, 20, 35};
    SDL_Rect photo2 = {5, 7, 20, 35};
    SDL_Rect photo3 = {5, 7, 20, 35};
    SDL_Rect photo4 = {5, 7, 20, 35};
    SDL_Rect photo5 = {5, 7, 20, 35};
    SDL_Rect photo02 = {5, 57, 20, 35};
    SDL_Rect photo12 = {5, 57, 20, 35};
    SDL_Rect photo22 = {5, 57, 20, 35};
    SDL_Rect photo32 = {5, 57, 20, 35};
    SDL_Rect photo42 = {5, 57, 20, 35};
    SDL_Rect photo52 = {5, 57, 20, 35};
    SDL_Rect texts = {100, 0, 600, 400};
    system("@mode con cols=55 lines=40");
    system("cls");
    while(!quit_all){
    SDL_Surface * menu_surface = IMG_Load("menu.png");
    SDL_Texture * menu_show = SDL_CreateTextureFromSurface(renderer, menu_surface);
    SDL_Rect menu_rect = { 0, 0, 800, 400 };
    SDL_RenderCopy(renderer, menu_show, NULL, &menu_rect);
    SDL_RenderPresent(renderer);
    system("cls");
    system("title Football Game Console");
    system("color 0d");
    system("echo Welcome To The Game");
    while (!quit_menu){
            first_click_read = false;
        while (SDL_PollEvent(&menu_event) == 1){
            SDL_GetMouseState( &x1, &y1 );
            while (x1>72 && x1<297 && y1>=114 && y1<=152){
                SDL_Rect pg_rect = { 61, 113, 250, 40 };
                SDL_RenderCopy(renderer, pg_show, NULL, &pg_rect);
                SDL_RenderPresent(renderer);
                if(voice==1){
                    PlaySound(TEXT("tagh.wav"), NULL, SND_FILENAME|SND_ASYNC|SND_NOSTOP);
                    voice++;
                }
                if (SDL_PollEvent(&menu_event) == 1){
                    SDL_GetMouseState(&x1,&y1);
                    if (y1<=144){
                        SDL_RenderCopy(renderer, menu_show, NULL, &menu_rect);
                        SDL_RenderPresent(renderer);
                    }
                    if (y1>=152){
                        SDL_RenderCopy(renderer, menu_show, NULL, &menu_rect);
                        SDL_RenderPresent(renderer);
                    }
                    if (x1<=72){
                        SDL_RenderCopy(renderer, menu_show, NULL, &menu_rect);
                        SDL_RenderPresent(renderer);
                    }
                    if (x1>=297){
                        SDL_RenderCopy(renderer, menu_show, NULL, &menu_rect);
                        SDL_RenderPresent(renderer);
                    }
                }
                if (menu_event.type == SDL_MOUSEBUTTONDOWN){
                    menu = 1;
                    quit_menu = true;
                    quit_all = true;
                    SDL_PollEvent(&menu_event) == 0;
                    break;
                }
            }
            voice=1;
            while (x1>72 && x1<297 && y1>=164 && y1<=202){
                SDL_Rect about_rect = { 61, 163, 250, 40 };
                SDL_RenderCopy(renderer, about_show, NULL, &about_rect);
                SDL_RenderPresent(renderer);
                if(voice==1){
                    PlaySound(TEXT("tagh.wav"), NULL, SND_FILENAME|SND_ASYNC|SND_NOSTOP);
                    voice++;
                }
                if (SDL_PollEvent(&menu_event) == 1){
                    SDL_GetMouseState(&x1,&y1);
                    if (y1<=164){
                        SDL_RenderCopy(renderer, menu_show, NULL, &menu_rect);
                        SDL_RenderPresent(renderer);
                    }
                    if (y1>=202){
                        SDL_RenderCopy(renderer, menu_show, NULL, &menu_rect);
                        SDL_RenderPresent(renderer);
                    }
                    if (x1<=72){
                        SDL_RenderCopy(renderer, menu_show, NULL, &menu_rect);
                        SDL_RenderPresent(renderer);
                    }
                    if (x1>=297){
                        SDL_RenderCopy(renderer, menu_show, NULL, &menu_rect);
                        SDL_RenderPresent(renderer);
                    }
                }
                if (menu_event.type == SDL_MOUSEBUTTONDOWN){
                    menu = 2;
                    quit_menu = true;
                    SDL_PollEvent(&menu_event) == 0;
                    break;
                }
            }
            voice=1;
            while (x1>72 && x1<297 && y1>=214 && y1<=252){
                SDL_Rect inf_rect = { 61, 213, 250, 40 };
                SDL_RenderCopy(renderer, inf_show, NULL, &inf_rect);
                SDL_RenderPresent(renderer);
                if(voice==1){
                    PlaySound(TEXT("tagh.wav"), NULL, SND_FILENAME|SND_ASYNC|SND_NOSTOP);
                    voice++;
                }
                if (SDL_PollEvent(&menu_event) == 1){
                    SDL_GetMouseState(&x1,&y1);
                    if (y1<=214){
                        SDL_RenderCopy(renderer, menu_show, NULL, &menu_rect);
                        SDL_RenderPresent(renderer);
                    }
                    if (y1>=252){
                        SDL_RenderCopy(renderer, menu_show, NULL, &menu_rect);
                        SDL_RenderPresent(renderer);
                    }
                    if (x1<=72){
                        SDL_RenderCopy(renderer, menu_show, NULL, &menu_rect);
                        SDL_RenderPresent(renderer);
                    }
                    if (x1>=297){
                        SDL_RenderCopy(renderer, menu_show, NULL, &menu_rect);
                        SDL_RenderPresent(renderer);
                    }
                }
                if (menu_event.type == SDL_MOUSEBUTTONDOWN){
                    menu = 3;
                    quit_menu = true;
                    SDL_PollEvent(&menu_event) == 0;
                    break;
                }
            }
            voice=1;
            SDL_Rect team_infos_rec = { 0, 0, 800, 400};
            if (x1>=540 && x1<=740 && y1>=35 && y1<=105){
                if (menu_event.type == SDL_MOUSEBUTTONDOWN){
                    first_click_read=true;
                    if (first_click_read==true) system("echo Take a time to read about Barcelona team :D");
                    SDL_RenderCopy(renderer, team_info_bc, NULL, &team_infos_rec);
                    SDL_RenderPresent(renderer);
                    quit_infos_team = false;
                    while (quit_infos_team != true){
                        if (SDL_PollEvent(&info_event) == 1){
                            if (info_event.type == SDL_MOUSEBUTTONDOWN){
                                quit_infos_team = true;
                                system("cls && echo Welcome To The Game");
                            }
                        }
                    }
                    SDL_RenderCopy(renderer, menu_show, NULL, &menu_rect);
                    SDL_RenderPresent(renderer);
                }
            }
            if (x1>=510 && x1<=765 && y1>=115 && y1<=190){
                if (menu_event.type == SDL_MOUSEBUTTONDOWN){
                    first_click_read=true;
                    if (first_click_read==true) system("echo Take a time to read about Manchester City team :D");
                    SDL_RenderCopy(renderer, team_info_mc, NULL, &team_infos_rec);
                    SDL_RenderPresent(renderer);
                    quit_infos_team = false;
                    while (quit_infos_team != true){
                        if (SDL_PollEvent(&info_event) == 1){
                            if (info_event.type == SDL_MOUSEBUTTONDOWN){
                                quit_infos_team = true;
                                system("cls && echo Welcome To The Game");
                            }
                        }
                    }
                    SDL_RenderCopy(renderer, menu_show, NULL, &menu_rect);
                    SDL_RenderPresent(renderer);
                }
            }
            if (x1>=470 && x1<=785 && y1>=200 && y1<=280){
                if (menu_event.type == SDL_MOUSEBUTTONDOWN){
                    first_click_read=true;
                    if (first_click_read==true) system("echo Take a time to read about Manchester United team :D");
                    SDL_RenderCopy(renderer, team_info_mu, NULL, &team_infos_rec);
                    SDL_RenderPresent(renderer);
                    quit_infos_team = false;
                    while (quit_infos_team != true){
                        if (SDL_PollEvent(&info_event) == 1){
                            if (info_event.type == SDL_MOUSEBUTTONDOWN){
                                quit_infos_team = true;
                                system("cls && echo Welcome To The Game");
                            }
                        }
                    }
                    SDL_RenderCopy(renderer, menu_show, NULL, &menu_rect);
                    SDL_RenderPresent(renderer);
                }
            }
            if (x1>=440 && x1<=780 && y1>=290 && y1<=370){
                if (menu_event.type == SDL_MOUSEBUTTONDOWN){
                    first_click_read=true;
                    if (first_click_read==true) system("echo Take a time to read about Real Madrid team :D");
                    SDL_RenderCopy(renderer, team_info_rm, NULL, &team_infos_rec);
                    SDL_RenderPresent(renderer);
                    quit_infos_team = false;
                    while (quit_infos_team != true){
                        if (SDL_PollEvent(&info_event) == 1){
                            if (info_event.type == SDL_MOUSEBUTTONDOWN){
                                quit_infos_team = true;
                                system("cls && echo Welcome To The Game");
                            }
                        }
                    }
                    SDL_RenderCopy(renderer, menu_show, NULL, &menu_rect);
                    SDL_RenderPresent(renderer);
                }
            }
        }
    }
    SDL_Surface * first = IMG_Load("info.png");
    SDL_Texture * info = SDL_CreateTextureFromSurface(renderer, first);
    SDL_Surface * second = IMG_Load("aboutus.png");
    SDL_Texture * aboutus = SDL_CreateTextureFromSurface(renderer, second);
    SDL_Rect info_b = { 0, 0, 800, 400 };
    SDL_Rect aboutus_b = { 0, 0, 800, 400 };
    if (menu == 2 && quit_aboutus == false){
        system("ping localhost -n 1 >nul && echo You are in about us part now");
        newline;
        system("echo   If you have any questions, tip, review, problem and");
        system("echo        anything else share with us via email:");
        system("echo              hasgroup2021@gmail.com :D");
        SDL_RenderCopy(renderer, aboutus, NULL, &aboutus_b);
        SDL_RenderCopy(renderer, aboutus_text_show, NULL, &texts);
        SDL_RenderPresent(renderer);
        while (quit_aboutus != true){
            if (SDL_PollEvent(&info_event) == 1){
                if (info_event.type == SDL_MOUSEBUTTONDOWN){
                     SDL_GetMouseState( &x_menu, &y_menu );
                     if(x_menu>25 && x_menu<200 && y_menu>165 && y_menu<235){
                         quit_menu = false;
                         quit_aboutus = true;
                     }
                     else if(x_menu>700 && x_menu<770 && y_menu>165 && y_menu<235){
                         quit_aboutus = true;
                         quit_all = true;
                     }
                }
            }
        }
        quit_aboutus = false;
    }
    if (menu == 3 && quit_info == false){
        system("ping localhost -n 1 >nul && echo You are in information part now");
        newline;
        system("echo Read carefully :)");
        SDL_RenderCopy(renderer, info, NULL, &info_b);
        SDL_RenderCopy(renderer, info_text_show, NULL, &texts);
        SDL_RenderPresent(renderer);
        while (quit_info != true){
            if (SDL_PollEvent(&info_event) == 1){
                if (info_event.type == SDL_MOUSEBUTTONDOWN){
                    SDL_GetMouseState( &x_menu2, &y_menu2 );
                     if(x_menu2>25 && x_menu2<200 && y_menu2>165 && y_menu2<235){
                         quit_menu = false;
                         quit_info = true;
                     }
                     else if(x_menu2>700 && x_menu2<770 && y_menu2>165 && y_menu2<235){
                         quit_info = true;
                         quit_all = true;
                     }
                }
            }
        }
        quit_info = false;
    }
    }
    SDL_Rect chooseteam_rect = { 0, 0, 800, 400};
    SDL_RenderCopy(renderer, chooseteam_show, NULL, &chooseteam_rect);
    SDL_RenderPresent(renderer);
    system("cls && echo Welcome To The Game");
    std::cout << "(Choose a Team for player 1)";
    while (!quit_teams){
        while (SDL_PollEvent(&teams_event) == 1){
            if (teams_event.type == SDL_MOUSEBUTTONDOWN){
                SDL_GetMouseState( &x_team, &y_team );
                if (x_team>0 && x_team<200 && y_team>93 && y_team<400){
                    choose_team = 4;
                    quit_teams = true;
                }
                else if (x_team>200 && x_team<400 && y_team>93 && y_team<400){
                    choose_team = 1;
                    quit_teams = true;
                }
                else if (x_team>400 && x_team<600 && y_team>93 && y_team<400){
                    choose_team = 3;
                    quit_teams = true;
                }
                else if (x_team>600 && x_team<800 && y_team>93 && y_team<400){
                    choose_team = 2;
                    quit_teams = true;
                }
                else continue;
            }
            else continue;
        }
    /* 1 = barcelona
     * 2 = man city
     * 3 = man united
     * 4 = real madrid
     */
    }
    for (int i=0;i<28;i++) print"\b";
    std::cout << "(Choose a Team for player 2)";
    SDL_Rect chooseteam2_rect = { 0, 0, 800, 400};
    SDL_RenderCopy(renderer, chooseteam2_show, NULL, &chooseteam2_rect);
    SDL_RenderPresent(renderer);
    quit_teams = false;
    while (!quit_teams){
        while (SDL_PollEvent(&teams_event) == 1){
            if (teams_event.type == SDL_MOUSEBUTTONDOWN){
                SDL_GetMouseState( &x_team, &y_team );
                if (x_team>0 && x_team<200 && y_team>93 && y_team<400){
                    choose_team_2 = 4;
                    quit_teams = true;
                }
                else if (x_team>200 && x_team<400 && y_team>93 && y_team<400){
                    choose_team_2 = 1;
                    quit_teams = true;
                }
                else if (x_team>400 && x_team<600 && y_team>93 && y_team<400){
                    choose_team_2 = 3;
                    quit_teams = true;
                }
                else if (x_team>600 && x_team<800 && y_team>93 && y_team<400){
                    choose_team_2 = 2;
                    quit_teams = true;
                }
                else continue;
            }
            else continue;
        }
    }
    for (int i=0;i<28;i++) print"\b";
    print "----------------------------\n";
    switch(choose_team){
    case 1:
        print "Player 1 = Barcelona";
        break;
    case 2:
        print "Player 1 = Manchester City";
        break;
    case 3:
        print "Player 1 = Manchester United";
        break;
    case 4:
        print "Player 1 = Real Madrid";
        break;
    default:
        return 0;
    }
    print"\n";
    switch(choose_team_2){
    case 1:
        print "Player 2 = Barcelona";
        break;
    case 2:
        print "Player 2 = Manchester City";
        break;
    case 3:
        print "Player 2 = Manchester United";
        break;
    case 4:
        print "Player 2 = Real Madrid";
        break;
    default:
        return 0;
    }
    newline;
    print "----------------------------\n";
    if(choose_team==1 && choose_team_2==2){
        SDL_Rect C_vs_B_rect = { 0, 0, 800, 400};
        SDL_RenderCopy(renderer, C_vs_B_show, NULL, &C_vs_B_rect);
        SDL_RenderPresent(renderer);
        SDL_Delay(2000);
    }
    else if(choose_team==2 && choose_team_2==1){
        SDL_Rect C_vs_B_rect = { 0, 0, 800, 400};
        SDL_RenderCopy(renderer, C_vs_B_show, NULL, &C_vs_B_rect);
        SDL_RenderPresent(renderer);
        SDL_Delay(2000);
    }
    else if(choose_team==3 && choose_team_2==1){
        SDL_Rect U_vs_B_rect = { 0, 0, 800, 400};
        SDL_RenderCopy(renderer, U_vs_B_show, NULL, &U_vs_B_rect);
        SDL_RenderPresent(renderer);
        SDL_Delay(2000);
    }
    else if(choose_team==1 && choose_team_2==3){
        SDL_Rect U_vs_B_rect = { 0, 0, 800, 400};
        SDL_RenderCopy(renderer, U_vs_B_show, NULL, &U_vs_B_rect);
        SDL_RenderPresent(renderer);
        SDL_Delay(2000);
    }
    else if(choose_team==1 && choose_team_2==4){
        SDL_Rect R_vs_B_rect = { 0, 0, 800, 400};
        SDL_RenderCopy(renderer, R_vs_B_show, NULL, &R_vs_B_rect);
        SDL_RenderPresent(renderer);
        SDL_Delay(2000);
    }
    else if(choose_team==4 && choose_team_2==1){
        SDL_Rect R_vs_B_rect = { 0, 0, 800, 400};
        SDL_RenderCopy(renderer, R_vs_B_show, NULL, &R_vs_B_rect);
        SDL_RenderPresent(renderer);
        SDL_Delay(2000);
    }
    else if(choose_team==4 && choose_team_2==2){
        SDL_Rect R_vs_C_rect = { 0, 0, 800, 400};
        SDL_RenderCopy(renderer, R_vs_C_show, NULL, &R_vs_C_rect);
        SDL_RenderPresent(renderer);
        SDL_Delay(2000);
    }
    else if(choose_team==2 && choose_team_2==4){
        SDL_Rect R_vs_C_rect = { 0, 0, 800, 400};
        SDL_RenderCopy(renderer, R_vs_C_show, NULL, &R_vs_C_rect);
        SDL_RenderPresent(renderer);
        SDL_Delay(2000);
    }
    else if(choose_team==2 && choose_team_2==3){
        SDL_Rect U_vs_C_rect = { 0, 0, 800, 400};
        SDL_RenderCopy(renderer, U_vs_C_show, NULL, &U_vs_C_rect);
        SDL_RenderPresent(renderer);
        SDL_Delay(2000);
    }
    else if(choose_team==3 && choose_team_2==2){
        SDL_Rect U_vs_C_rect = { 0, 0, 800, 400};
        SDL_RenderCopy(renderer, U_vs_C_show, NULL, &U_vs_C_rect);
        SDL_RenderPresent(renderer);
        SDL_Delay(2000);
    }
    else if(choose_team==4 && choose_team_2==3){
        SDL_Rect U_vs_R_rect = { 0, 0, 800, 400};
        SDL_RenderCopy(renderer, U_vs_R_show, NULL, &U_vs_R_rect);
        SDL_RenderPresent(renderer);
        SDL_Delay(2000);
    }
    else if(choose_team==3 && choose_team_2==4){
        SDL_Rect U_vs_R_rect = { 0, 0, 800, 400};
        SDL_RenderCopy(renderer, U_vs_R_show, NULL, &U_vs_R_rect);
        SDL_RenderPresent(renderer);
        SDL_Delay(2000);
    }
    SDL_Surface * gk_bc[9] = {IMG_Load("bc_1-2.png"),IMG_Load("bc_3-8-13.png"),IMG_Load("bc_4-5.png"),
        IMG_Load("bc_6.png"),IMG_Load("bc_7-12.png"),IMG_Load("bc_9-14.png"),IMG_Load("bc_10.png"),IMG_Load("bc_11.png"),IMG_Load("bc_15.png")};
    SDL_Surface * gk_mc[9] = {IMG_Load("mc_1-2.png"),IMG_Load("mc_3-8-13.png"),IMG_Load("mc_4-5.png"),
        IMG_Load("mc_6.png"),IMG_Load("mc_7-12.png"),IMG_Load("mc_9-14.png"),IMG_Load("mc_10.png"),IMG_Load("mc_11.png"),IMG_Load("mc_15.png")};
    SDL_Surface * gk_mu[9] = {IMG_Load("mu_1-2.png"),IMG_Load("mu_3-8-13.png"),IMG_Load("mu_4-5.png"),
        IMG_Load("mu_6.png"),IMG_Load("mu_7-12.png"),IMG_Load("mu_9-14.png"),IMG_Load("mu_10.png"),IMG_Load("mu_11.png"),IMG_Load("mu_15.png")};
    SDL_Surface * gk_rm[9] = {IMG_Load("rm_1-2.png"),IMG_Load("rm_3-8-13.png"),IMG_Load("rm_4-5.png"),
        IMG_Load("rm_6.png"),IMG_Load("rm_7-12.png"),IMG_Load("rm_9-14.png"),IMG_Load("rm_10.png"),IMG_Load("rm_11.png"),IMG_Load("rm_15.png")};
    SDL_Rect first_gk = { 358, 190, 100, 125};
    if (choose_team_2 == 1){
        SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_bc[1]);
        SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
    }
    else if (choose_team_2 == 2){
        SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mc[1]);
        SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
    }
    else if (choose_team_2 == 3){
        SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mu[1]);
        SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
    }
    else {
        SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_rm[1]);
        SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
    }
    quit = false;
    std::cout << "            Turn 1  : Player 1 Is Shooter \n";
    goal_bool=false;
    print("Waiting for player 1 to shoot...");
    first_click_player1=false;
    while (!quit){
        while(SDL_PollEvent(&e) != 0 ){
            if(e.type == SDL_QUIT){
                quit = true;
            }
            else if(e.type == SDL_MOUSEBUTTONDOWN){
                if (first_click_player1==false){
                    first_click_player1=true;
                    for(int i=0;i<32;i++) print"\b";
                    print("Waiting for player 2 to save... ");
                }
                SDL_Rect image_back = { 0, 0, 800, 400 };
                SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                SDL_RenderPresent(renderer);
                PlaySound(NULL, 0, 0);
                PlaySound(TEXT("quite.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                int x,y;
                SDL_GetMouseState( &x, &y );
                keydown = false;
                while (!keydown){
                        PlaySound(NULL, 0, 0);
                        PlaySound(TEXT("quite.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
                        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
                        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
                        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
                        if (choose_team_2 == 1){
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_bc[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mc[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mu[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        else {
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_rm[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        if(choose_team == 1){
                            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        if(choose_team == 2){
                            SDL_Rect Man_City_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        if(choose_team == 3){
                            SDL_Rect Man_United_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        if(choose_team == 4){
                            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        if (choose_team_2 == 1){
                            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Rect Man_City_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Rect Man_United_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        else {
                            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                        SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                        SDL_RenderPresent(renderer);
                    first_click_player2=false;
                    while (SDL_PollEvent(&saver)!=0){
                        SDL_WaitEvent(&saver);
                        if (saver.type == SDL_KEYDOWN){
                            if (saver.key.keysym.sym == SDLK_q){
                                keydown = true;
                                goalkeeper_pos = 1;
                            }
                            else if (saver.key.keysym.sym == SDLK_w){
                                keydown = true;
                                goalkeeper_pos = 2;
                            }
                            else if (saver.key.keysym.sym == SDLK_e){
                                keydown = true;
                                goalkeeper_pos = 3;
                            }
                            else if (saver.key.keysym.sym == SDLK_a){
                                keydown = true;
                                goalkeeper_pos = 4;
                            }
                            else if (saver.key.keysym.sym == SDLK_d){
                                keydown = true;
                                goalkeeper_pos = 6;
                            }
                        else{
                            keydown = true;
                            goalkeeper_pos = 5;
                        }
                            if (first_click_player2==false){
                                first_click_player2=true;
                                for(int i=0;i<32;i++) print"\b";
                                print"Both players had decided... Lets see what happen :)";
                                newline;
                            }
                        }
                    }
                }
                if (x<236 && x>=120 && y<190 && y>=135) mouse_pos = 1;
                else if (x<352 && x>=236 && y<190 && y>=135) mouse_pos = 2;
                else if (x<468 && x>=352 && y<190 && y>=135) mouse_pos = 3;
                else if (x<584 && x>=468 && y<190 && y>=135) mouse_pos = 4;
                else if (x<=700 && x>=584 && y<190 && y>=135) mouse_pos = 5;
                else if (x<236 && x>=120 && y<245 && y>=190) mouse_pos = 6;
                else if (x<352 && x>=236 && y<245 && y>=190) mouse_pos = 7;
                else if (x<468 && x>=352 && y<245 && y>=190) mouse_pos = 8;
                else if (x<584 && x>=468 && y<245 && y>=190) mouse_pos = 9;
                else if (x<=700 && x>=584 && y<245 && y>=190) mouse_pos = 10;
                else if (x<236 && x>=120 && y<=300 && y>=245) mouse_pos = 11;
                else if (x<352 && x>=236 && y<=300 && y>=245) mouse_pos = 12;
                else if (x<468 && x>=352 && y<=300 && y>=245) mouse_pos = 13;
                else if (x<584 && x>=468 && y<=300 && y>=245) mouse_pos = 14;
                else if (x<=700 && x>=584 && y<=300 && y>=245) mouse_pos = 15;
                if (mouse_pos == 1 || mouse_pos == 2) gk_num = 0;
                else if (mouse_pos == 3 || mouse_pos == 8 || mouse_pos == 13) gk_num = 1;
                else if (mouse_pos == 4 || mouse_pos == 5) gk_num = 2;
                else if (mouse_pos == 6) gk_num = 3;
                else if (mouse_pos == 7 || mouse_pos == 12) gk_num = 4;
                else if (mouse_pos == 9 || mouse_pos == 14) gk_num = 5;
                else if (mouse_pos == 10) gk_num = 6;
                else if (mouse_pos == 11) gk_num = 7;
                else if (mouse_pos == 15) gk_num = 8;
                if(gk_num==0){
                    x_chap=125;
                    y_chap=100;
                }
                else if(gk_num==1){
                    x_chap=100;
                    y_chap=125;
                }
                else if(gk_num==2){
                    x_chap=125;
                    y_chap=100;
                }
                else if(gk_num==3){
                    x_chap=150;
                    y_chap=100;
                }
                else if(gk_num==4){
                    x_chap=107;
                    y_chap=110;
                }
                else if(gk_num==5){
                    x_chap=107;
                    y_chap=110;
                }
                else if(gk_num==6){
                    x_chap=150;
                    y_chap=100;
                }
                else if(gk_num==7){
                    x_chap=150;
                    y_chap=100;
                }
                else if(gk_num==8){
                    x_chap=150;
                    y_chap=100;
                }
                same_direction = false;
                if (goalkeeper_pos == 1){
                    if (mouse_pos == 1 || mouse_pos == 2 || mouse_pos == 6 || mouse_pos == 7) same_direction = true;
                }
                else if (goalkeeper_pos == 2){
                    if (mouse_pos == 3 || mouse_pos == 8) same_direction = true;
                }
                else if (goalkeeper_pos == 3){
                    if (mouse_pos == 4 || mouse_pos == 5 || mouse_pos == 9 || mouse_pos == 10) same_direction = true;
                }
                else if (goalkeeper_pos == 4){
                    if (mouse_pos == 11 || mouse_pos == 12) same_direction = true;
                }
                else if (goalkeeper_pos == 5){
                    if (mouse_pos == 8 || mouse_pos == 13) same_direction = true;
                }
                else if (goalkeeper_pos == 6){
                    if (mouse_pos == 14 || mouse_pos == 15) same_direction = true;
                }
                if (same_direction != true){
                    if (goalkeeper_pos==1) gk_num = 0;
                    else if (goalkeeper_pos==2) gk_num = 1;
                    else if (goalkeeper_pos==3) gk_num = 2;
                    else if (goalkeeper_pos==4) gk_num = 3;
                    else if (goalkeeper_pos==5) gk_num = 1;
                    else if (goalkeeper_pos==6) gk_num = 6;
                }
                if(x>=x_ball){
                    fx=x-370;
                    fy=320-y;
                    bx=fx%10;
                    by=fy%10;
                    if(bx==1)
                        fx-=1;
                    else if(bx==2)
                        fx-=2;
                    else if(bx==3)
                        fx-=3;
                    else if(bx==4)
                        fx-=4;
                    else if(bx==5)
                        fx+=5;
                    else if(bx==6)
                        fx+=4;
                    else if(bx==7)
                        fx+=3;
                    else if(bx==8)
                        fx+=2;
                    else if(bx==9)
                        fx+=1;
                    if(by==1)
                        fy-=1;
                    else if(by==2)
                        fy-=2;
                    else if(by==3)
                        fy-=3;
                    else if(by==4)
                        fy-=4;
                    else if(by==5)
                        fy+=5;
                    else if(by==6)
                        fy+=4;
                    else if(by==7)
                        fy+=3;
                    else if(by==8)
                        fy+=2;
                    else if(by==9)
                        fy+=1;
                    fx=fx/10;
                    fy=fy/10;
                    while(sh<18){
                        if (mouse_pos == 3 && y_gk>135 && same_direction == true){
                            y_gk-=4;
                        }
                        if (mouse_pos == 4 && y_gk>135 && same_direction == true){
                            x_gk+=8;
                            y_gk-=3;
                        }
                        if (mouse_pos == 5 && y_gk>135 && same_direction == true){
                            x_gk+=14;
                            y_gk-=3;
                        }
                        if (mouse_pos == 8 && same_direction == true){
                            y_gk-=1;
                        }
                        if (mouse_pos == 9 && x_gk<584 && same_direction == true){
                            x_gk+=7;
                            y_gk-=1;
                        }
                        if (mouse_pos == 10 && x_gk<=600 && same_direction == true){
                            x_gk+=12;
                            y_gk-=2;
                        }
                        if (mouse_pos == 14 && x_gk<=584 && same_direction == true){
                            x_gk+=9;
                        }
                        if (mouse_pos == 15 && x_gk<=600 && same_direction == true){
                            x_gk+=13;
                        }
                        if (same_direction == false){
                            if (goalkeeper_pos == 1){
                                x_gk-=13;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 2){
                                y_gk-=4;
                            }
                            if (goalkeeper_pos == 3){
                                x_gk+=14;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 4){
                                x_gk-=13;
                                y_gk-=1;
                            }
                            if (goalkeeper_pos == 5){
                                //nothing
                            }
                            if (goalkeeper_pos == 6){
                                x_gk+=14;
                                y_gk-=1;
                            }
                        }
                        if (x_gk+30<468 && x_gk+30>=352 && y_gk+10<190 && y_gk+10>=135 && gk_num == 1) gk_pos = 3; // 60 35
                        else if (x_gk+100<584 && x_gk+100>=468 && y_gk+10<190 && y_gk+10>=135 && gk_num == 2) gk_pos = 4; // 170 45
                        else if (x_gk+100<=700 && x_gk+100>=584 && y_gk+10<190 && y_gk+10>=135 && gk_num == 2) gk_pos = 5; // 170 45
                        else if (x_gk+30<468 && x_gk+30>=352 && y_gk+10<245 && y_gk+10>=190 && gk_num == 1) gk_pos = 8; // 60 35
                        else if (x_gk+180<584 && x_gk+180>=468 && y_gk+40<245 && y_gk+40>=190 && gk_num == 5) gk_pos = 9; // 180 80
                        else if (x_gk+170<=700 && x_gk+170>=584 && y_gk+50<245 && y_gk+50>=190 && gk_num == 6) gk_pos = 10; // 210 100
                        else if (x_gk+30<468 && x_gk+30>=352 && y_gk+100<=300 && y_gk+100>=245 && gk_num == 1) gk_pos = 13; // 60 35
                        else if (x_gk+10<584 && x_gk+10>=468 && y_gk+50<=300 && y_gk+50>=245 && gk_num == 5) gk_pos = 14; // 180 80
                        else if (x_gk+200<=700 && x_gk+200>=584 && y_gk+100<=300 && y_gk+100>=245 && gk_num == 8) gk_pos = 15; // 270 140
                        if(sh%2==0){
                            x_ball+=fx/2;
                            y_ball-=fy/2;
                        }
                        else{
                            x_ball+=fx;
                            y_ball-=fy;
                        }
                        if (gk_pos == 9 && mouse_pos == 14) gk_pos=mouse_pos;
                        if (gk_pos == 8 && mouse_pos == 13) gk_pos=mouse_pos;
                        //std::cout<<gk_pos<<"\t"<<mouse_pos<<"\n";
                        if(y_ball-fy<=y && gk_pos==mouse_pos && x_ball-fx<=x && goal_bool==false){
                            print"Result : Player 2 saved the goal";newline;newline;
                            PlaySound(NULL, 0, 0);
                            PlaySound(TEXT("no_goal.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                            SDL_Rect save_rect = { 0, 0, 800, 400};
                            if(choose_team_2 == 1){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, bc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            else if(choose_team_2 == 2){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            else if(choose_team_2 == 3){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mu_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            else{
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, rm_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            sh=18;
                        }
                        else if(same_direction == false && y_ball-fy<=y && x_ball-fx<=x){
                            print"Result : Player 1 scored the goal";newline;newline;
                            results[0]=1;
                            number++;
                            SDL_Rect score_rect = { 0, 0, 800, 400};
                            SDL_RenderCopy(renderer, score_show, NULL, &score_rect);
                            SDL_Delay(500);
                            SDL_RenderPresent(renderer);
                            SDL_Delay(2000);
                            sh=18;
                        }
                        if(sh>=9)
                            aa-=5*a;
                        else
                            aa-=a;
                        if(h%3==0)
                            a++;
                        sh++;
                        SDL_Rect image_back = { 0, 0, 800, 400 };
                        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                        SDL_RenderPresent(renderer);
                        if (choose_team_2 == 1){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_bc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team_2 == 2){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team_2 == 3){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mu[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else{
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_rm[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
                        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
                        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
                        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
                        if(choose_team == 1){
                            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        if(choose_team == 2){
                            SDL_Rect Man_City_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        if(choose_team == 3){
                            SDL_Rect Man_United_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        if(choose_team == 4){
                            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        if (choose_team_2 == 1){
                            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Rect Man_City_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Rect Man_United_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        else {
                            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        SDL_RenderPresent(renderer);
                        h++;
                        if(h==6)
                            h=1;
                        SDL_Delay(200);
                        if (sh==10){
                            SDL_Delay(200);
                            quit=true;
                        }
                    }
                }
                else if(x<x_ball){
                    fx=370-x;
                    fy=320-y;
                    bx=fx%10;
                    by=fy%10;
                    if(bx==1)
                        fx-=1;
                    else if(bx==2)
                        fx-=2;
                    else if(bx==3)
                        fx-=3;
                    else if(bx==4)
                        fx-=4;
                    else if(bx==5)
                        fx+=5;
                    else if(bx==6)
                        fx+=4;
                    else if(bx==7)
                        fx+=3;
                    else if(bx==8)
                        fx+=2;
                    else if(bx==9)
                        fx+=1;
                    if(by==1)
                        fy-=1;
                    else if(by==2)
                        fy-=2;
                    else if(by==3)
                        fy-=3;
                    else if(by==4)
                        fy-=4;
                    else if(by==5)
                        fy+=5;
                    else if(by==6)
                        fy+=4;
                    else if(by==7)
                        fy+=3;
                    else if(by==8)
                        fy+=2;
                    else if(by==9)
                        fy+=1;
                    fx=fx/10;
                    fy=fy/10;
                    while(sh<18){
                        if (mouse_pos == 1 && x_gk>120 && same_direction == true){
                            x_gk-=14;
                            y_gk-=3;
                        }
                        if (mouse_pos == 2 && y_gk>135 && same_direction == true){
                            x_gk-=5;
                            y_gk-=3;
                        }
                        if (mouse_pos == 6 && x_gk>110 && same_direction == true){
                            x_gk-=12;
                            y_gk-=2;
                        }
                        if (mouse_pos == 7 && x_gk>=236 && same_direction == true){
                            x_gk-=6;
                            y_gk-=1;
                        }
                        if (mouse_pos == 11 && x_gk>120 && same_direction == true){
                            x_gk-=13;
                        }
                        if (mouse_pos == 12 && x_gk>=236 && same_direction == true){
                            x_gk-=7;
                        }
                        if (same_direction == false){
                            if (goalkeeper_pos == 1){
                                x_gk-=13;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 2){
                                y_gk-=4;
                            }
                            if (goalkeeper_pos == 3){
                                x_gk+=14;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 4){
                                x_gk-=13;
                                y_gk-=1;
                            }
                            if (goalkeeper_pos == 5){
                                //nothing
                            }
                            if (goalkeeper_pos == 6){
                                x_gk+=14;
                                y_gk-=1;
                            }
                        }
                        if (x_gk+15<236 && x_gk+15>=120 && y_gk+25<190 && y_gk+25>=135 && gk_num == 0) gk_pos = 1;
                        else if (x_gk+15<352 && x_gk+15>=236 && y_gk+15<190 && y_gk+15>=135 && gk_num == 0) gk_pos = 2;
                        else if (x_gk<236 && x_gk>=120 && y_gk+50<245 && y_gk+50>=190 && gk_num == 3) gk_pos = 6; // 15 100
                        else if (x_gk+10<352 && x_gk+10>=236 && y_gk+50<245 && y_gk+50>=190 && gk_num == 4) gk_pos = 7; // 20 80
                        else if (x_gk<236 && x_gk>=120 && y_gk+70<=300 && y_gk+70>=245 && gk_num == 7) gk_pos = 11; // 35 140
                        else if (x_gk+10<352 && x_gk+10>=236 && y_gk+50<=300 && y_gk+50>=245 && gk_num == 4) gk_pos = 12; // 20 80
                        else if (x_gk+30<468 && x_gk+30>=352 && y_gk+200<=300 && y_gk+200>=245 && gk_num == 1) gk_pos = 13; // 60 35
                        if(sh%2==0){
                            x_ball-=fx/2;
                            y_ball-=fy/2;
                        }
                        else{
                            x_ball-=fx;
                            y_ball-=fy;
                        }
                        //std::cout<<gk_pos<<"\t"<<mouse_pos<<"\n";
                        if (gk_pos == 8 && mouse_pos == 13) gk_pos=mouse_pos;
                        if(y_ball-fy<=y && gk_pos==mouse_pos && x_ball-fx<=x && goal_bool==false){
                            print"Result : Player 2 saved the goal";newline;newline;
                            PlaySound(NULL, 0, 0);
                            SDL_Delay(200);
                            PlaySound(TEXT("no_goal.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                            SDL_Rect save_rect = { 0, 0, 800, 400};
                            if(choose_team_2 == 1){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, bc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            else if(choose_team_2 == 2){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            else if(choose_team_2 == 3){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mu_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            else{
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, rm_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            sh=18;
                        }
                        else if(same_direction == false && y_ball-fy<=y && x_ball-fx<=x){
                            print"Result : Player 1 scored the goal";newline;newline;
                            results[0]=1;
                            number++;
                            SDL_Rect score_rect = { 0, 0, 800, 400};
                            SDL_RenderCopy(renderer, score_show, NULL, &score_rect);
                            SDL_Delay(500);
                            SDL_RenderPresent(renderer);
                            SDL_Delay(2000);
                            sh=18;
                        }
                        //std::cout<<number;
                        if(sh>=9)
                            aa-=5*a;
                        else
                            aa-=a;
                        if(h%3==0)
                            a++;
                        sh++;
                        SDL_Rect image_back = { 0, 0, 800, 400 };
                        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                        SDL_RenderPresent(renderer);
                        if (choose_team_2 == 1){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_bc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team_2 == 2){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team_2 == 3){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mu[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else{
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_rm[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
                        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
                        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
                        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
                        if(choose_team == 1){
                            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        if(choose_team == 2){
                            SDL_Rect Man_City_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        if(choose_team == 3){
                            SDL_Rect Man_United_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        if(choose_team == 4){
                            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        if (choose_team_2 == 1){
                            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Rect Man_City_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Rect Man_United_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        else {
                            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        SDL_RenderPresent(renderer);
                        h++;
                        if(h==6)
                            h=1;
                        SDL_Delay(200);
                        if (sh==10){
                            SDL_Delay(200);
                            quit=true;
                        }
                    }
                }
            }
        }
        //SDL_RenderPresent(renderer);
        SDL_Rect image_back = { 0, 0, 800, 400 };
        SDL_Rect ball1 = { 370, 320, 75, 75};
        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
        SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
        if(choose_team == 1){
            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
        }
        if(choose_team == 2){
            SDL_Rect Man_City_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
        }
        if(choose_team == 3){
            SDL_Rect Man_United_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
        }
        if(choose_team == 4){
            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
        }
        if (choose_team_2 == 1){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_bc[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
        }
        else if (choose_team_2 == 2){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mc[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Man_City_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
        }
        else if (choose_team_2 == 3){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mu[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Man_United_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
        }
        else {
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_rm[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
        }
        SDL_RenderPresent(renderer);
        if(voice==1){
            PlaySound(TEXT("cheering.wav"), NULL, SND_NOSTOP|SND_ASYNC);
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    x_ball=370,y_ball=320,fx=0,fy=0,sh=0,h=1,aa=75,a=0,voice=1;
    x_gk=345,y_gk=200;
    bx=0,by=0;
    int x=0,y=0;
    /*if (choose_team == 1){
        SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_bc[1]);
        SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
    }
    else if (choose_team == 2){
        SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mc[1]);
        SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
    }
    else if (choose_team == 3){
        SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mu[1]);
        SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
    }
    else {
        SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_rm[1]);
        SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
    }*/
    quit = false;
    goal_bool=false;
    first_click_player1=false;
    first_click_player2=false;
    std::cout << "            Turn 2  : Player 2 Is Shooter \n";
    print("Waiting for player 2 to shoot...");
    while (!quit){
        while(SDL_PollEvent(&e) != 0 ){
            if(e.type == SDL_QUIT){
                quit = true;
            }
            else if(e.type == SDL_MOUSEBUTTONDOWN){
                if (first_click_player1==false){
                    first_click_player1=true;
                    for(int i=0;i<32;i++) print"\b";
                    print("Waiting for player 1 to save... ");
                }
                SDL_Rect image_back = { 0, 0, 800, 400 };
                SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                SDL_RenderPresent(renderer);
                int x,y;
                SDL_GetMouseState( &x, &y );
                keydown = false;
                while (!keydown){
                        PlaySound(NULL, 0, 0);
                        PlaySound(TEXT("quite.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
                        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
                        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
                        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
                        if (choose_team == 1){
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_bc[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        else if (choose_team == 2){
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mc[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        else if (choose_team == 3){
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mu[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        else {
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_rm[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        if(choose_team == 1){
                            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        if(choose_team == 2){
                            SDL_Rect Man_City_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        if(choose_team == 3){
                            SDL_Rect Man_United_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        if(choose_team == 4){
                            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        if (choose_team_2 == 1){
                            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Rect Man_City_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Rect Man_United_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        else {
                            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                        SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                        SDL_RenderPresent(renderer);
                    while (SDL_PollEvent(&saver)!=0){
                        SDL_WaitEvent(&saver);
                        if (saver.type == SDL_KEYDOWN){
                            if (saver.key.keysym.sym == SDLK_q){
                                keydown = true;
                                goalkeeper_pos = 1;
                            }
                            else if (saver.key.keysym.sym == SDLK_w){
                                keydown = true;
                                goalkeeper_pos = 2;
                            }
                            else if (saver.key.keysym.sym == SDLK_e){
                                keydown = true;
                                goalkeeper_pos = 3;
                            }
                            else if (saver.key.keysym.sym == SDLK_a){
                                keydown = true;
                                goalkeeper_pos = 4;
                            }
                            else if (saver.key.keysym.sym == SDLK_d){
                                keydown = true;
                                goalkeeper_pos = 6;
                            }
                        else{
                            keydown = true;
                            goalkeeper_pos = 5;
                        }
                        if (first_click_player2==false){
                                first_click_player2=true;
                                for(int i=0;i<32;i++) print"\b";
                                print"Both players had decided... Lets see what happen :)";
                                newline;
                            }
                        }
                    }
                }
                if (x<236 && x>=120 && y<190 && y>=135) mouse_pos = 1;
                else if (x<352 && x>=236 && y<190 && y>=135) mouse_pos = 2;
                else if (x<468 && x>=352 && y<190 && y>=135) mouse_pos = 3;
                else if (x<584 && x>=468 && y<190 && y>=135) mouse_pos = 4;
                else if (x<=700 && x>=584 && y<190 && y>=135) mouse_pos = 5;
                else if (x<236 && x>=120 && y<245 && y>=190) mouse_pos = 6;
                else if (x<352 && x>=236 && y<245 && y>=190) mouse_pos = 7;
                else if (x<468 && x>=352 && y<245 && y>=190) mouse_pos = 8;
                else if (x<584 && x>=468 && y<245 && y>=190) mouse_pos = 9;
                else if (x<=700 && x>=584 && y<245 && y>=190) mouse_pos = 10;
                else if (x<236 && x>=120 && y<=300 && y>=245) mouse_pos = 11;
                else if (x<352 && x>=236 && y<=300 && y>=245) mouse_pos = 12;
                else if (x<468 && x>=352 && y<=300 && y>=245) mouse_pos = 13;
                else if (x<584 && x>=468 && y<=300 && y>=245) mouse_pos = 14;
                else if (x<=700 && x>=584 && y<=300 && y>=245) mouse_pos = 15;
                // 1 6 11 // 2 7 12 // 3 8 13 // 4 9 14 // 5 10 15
                if (mouse_pos == 1 || mouse_pos == 2) gk_num = 0;
                else if (mouse_pos == 3 || mouse_pos == 8 || mouse_pos == 13) gk_num = 1;
                else if (mouse_pos == 4 || mouse_pos == 5) gk_num = 2;
                else if (mouse_pos == 6) gk_num = 3;
                else if (mouse_pos == 7 || mouse_pos == 12) gk_num = 4;
                else if (mouse_pos == 9 || mouse_pos == 14) gk_num = 5;
                else if (mouse_pos == 10) gk_num = 6;
                else if (mouse_pos == 11) gk_num = 7;
                else if (mouse_pos == 15) gk_num = 8;
                if(gk_num==0){
                    x_chap=125;
                    y_chap=100;
                }
                else if(gk_num==1){
                    x_chap=100;
                    y_chap=125;
                }
                else if(gk_num==2){
                    x_chap=125;
                    y_chap=100;
                }
                else if(gk_num==3){
                    x_chap=150;
                    y_chap=100;
                }
                else if(gk_num==4){
                    x_chap=107;
                    y_chap=110;
                }
                else if(gk_num==5){
                    x_chap=107;
                    y_chap=110;
                }
                else if(gk_num==6){
                    x_chap=150;
                    y_chap=100;
                }
                else if(gk_num==7){
                    x_chap=150;
                    y_chap=100;
                }
                else if(gk_num==8){
                    x_chap=150;
                    y_chap=100;
                }
                same_direction = false;
                if (goalkeeper_pos == 1){
                    if (mouse_pos == 1 || mouse_pos == 2 || mouse_pos == 6 || mouse_pos == 7) same_direction = true;
                }
                else if (goalkeeper_pos == 2){
                    if (mouse_pos == 3 || mouse_pos == 8) same_direction = true;
                }
                else if (goalkeeper_pos == 3){
                    if (mouse_pos == 4 || mouse_pos == 5 || mouse_pos == 9 || mouse_pos == 10) same_direction = true;
                }
                else if (goalkeeper_pos == 4){
                    if (mouse_pos == 11 || mouse_pos == 12) same_direction = true;
                }
                else if (goalkeeper_pos == 5){
                    if (mouse_pos == 8 || mouse_pos == 13) same_direction = true;
                }
                else if (goalkeeper_pos == 6){
                    if (mouse_pos == 14 || mouse_pos == 15) same_direction = true;
                }
                if (same_direction != true){
                    if (goalkeeper_pos==1) gk_num = 0;
                    else if (goalkeeper_pos==2) gk_num = 1;
                    else if (goalkeeper_pos==3) gk_num = 2;
                    else if (goalkeeper_pos==4) gk_num = 3;
                    else if (goalkeeper_pos==5) gk_num = 1;
                    else if (goalkeeper_pos==6) gk_num = 6;
                }
                if(x>=x_ball){
                    fx=x-370;
                    fy=320-y;
                    bx=fx%10;
                    by=fy%10;
                    if(bx==1)
                        fx-=1;
                    else if(bx==2)
                        fx-=2;
                    else if(bx==3)
                        fx-=3;
                    else if(bx==4)
                        fx-=4;
                    else if(bx==5)
                        fx+=5;
                    else if(bx==6)
                        fx+=4;
                    else if(bx==7)
                        fx+=3;
                    else if(bx==8)
                        fx+=2;
                    else if(bx==9)
                        fx+=1;
                    if(by==1)
                        fy-=1;
                    else if(by==2)
                        fy-=2;
                    else if(by==3)
                        fy-=3;
                    else if(by==4)
                        fy-=4;
                    else if(by==5)
                        fy+=5;
                    else if(by==6)
                        fy+=4;
                    else if(by==7)
                        fy+=3;
                    else if(by==8)
                        fy+=2;
                    else if(by==9)
                        fy+=1;
                    fx=fx/10;
                    fy=fy/10;
                    while(sh<18){
                        if (mouse_pos == 3 && y_gk>135 && same_direction == true){
                            y_gk-=4;
                        }
                        if (mouse_pos == 4 && y_gk>135 && same_direction == true){
                            x_gk+=8;
                            y_gk-=3;
                        }
                        if (mouse_pos == 5 && y_gk>135 && same_direction == true){
                            x_gk+=14;
                            y_gk-=3;
                        }
                        if (mouse_pos == 8 && same_direction == true){
                            y_gk-=1;
                        }
                        if (mouse_pos == 9 && x_gk<584 && same_direction == true){
                            x_gk+=7;
                            y_gk-=1;
                        }
                        if (mouse_pos == 10 && x_gk<=600 && same_direction == true){
                            x_gk+=12;
                            y_gk-=2;
                        }
                        if (mouse_pos == 14 && x_gk<=584 && same_direction == true){
                            x_gk+=9;
                        }
                        if (mouse_pos == 15 && x_gk<=600 && same_direction == true){
                            x_gk+=13;
                        }
                        if (same_direction == false){
                            if (goalkeeper_pos == 1){
                                x_gk-=13;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 2){
                                y_gk-=4;
                            }
                            if (goalkeeper_pos == 3){
                                x_gk+=14;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 4){
                                x_gk-=13;
                                y_gk-=1;
                            }
                            if (goalkeeper_pos == 5){
                                //nothing
                            }
                            if (goalkeeper_pos == 6){
                                x_gk+=14;
                                y_gk-=1;
                            }
                        }
                        if(sh%2==0){
                            x_ball+=fx/2;
                            y_ball-=fy/2;
                        }
                        else{
                            x_ball+=fx;
                            y_ball-=fy;
                        }
                        if(same_direction == true && y_ball-fy<=y && x_ball-fx<=x){
                            print"Result : Player 1 saved the goal";newline;newline;
                            PlaySound(NULL, 0, 0);
                            PlaySound(TEXT("no_goal.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                            SDL_Rect save_rect = { 0, 0, 800, 400};
                            if(choose_team == 1){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, bc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            else if(choose_team == 2){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            else if(choose_team == 3){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mu_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            else{
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, rm_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            sh=18;
                        }
                        else if(same_direction == false && y_ball-fy<=y && x_ball-fx<=x){
                            print"Result : Player 2 scored the goal";newline;newline;
                            results[1]=1;
                            number2++;
                            SDL_Rect score_rect = { 0, 0, 800, 400};
                            SDL_RenderCopy(renderer, score_show, NULL, &score_rect);
                            SDL_Delay(500);
                            SDL_RenderPresent(renderer);
                            SDL_Delay(2000);
                            sh=18;
                        }
                        if(sh>=9)
                            aa-=5*a;
                        else
                            aa-=a;
                        if(h%3==0)
                            a++;
                        sh++;
                        SDL_Rect image_back = { 0, 0, 800, 400 };
                        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                        SDL_RenderPresent(renderer);
                        if (choose_team == 1){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_bc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team == 2){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team == 3){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mu[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else{
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_rm[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
                        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
                        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
                        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
                        //std::cout<<number2;
                        if(choose_team == 1){
                            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        if(choose_team == 2){
                            SDL_Rect Man_City_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        if(choose_team == 3){
                            SDL_Rect Man_United_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        if(choose_team == 4){
                            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        if (choose_team_2 == 1){
                            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Rect Man_City_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Rect Man_United_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        else {
                            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        SDL_RenderPresent(renderer);
                        h++;
                        if(h==6)
                            h=1;
                        SDL_Delay(200);
                        if (sh==10){
                            SDL_Delay(200);
                            quit = true;
                        }
                    }
                }
                else if(x<x_ball){
                    fx=370-x;
                    fy=320-y;
                    bx=fx%10;
                    by=fy%10;
                    if(bx==1)
                        fx-=1;
                    else if(bx==2)
                        fx-=2;
                    else if(bx==3)
                        fx-=3;
                    else if(bx==4)
                        fx-=4;
                    else if(bx==5)
                        fx+=5;
                    else if(bx==6)
                        fx+=4;
                    else if(bx==7)
                        fx+=3;
                    else if(bx==8)
                        fx+=2;
                    else if(bx==9)
                        fx+=1;
                    if(by==1)
                        fy-=1;
                    else if(by==2)
                        fy-=2;
                    else if(by==3)
                        fy-=3;
                    else if(by==4)
                        fy-=4;
                    else if(by==5)
                        fy+=5;
                    else if(by==6)
                        fy+=4;
                    else if(by==7)
                        fy+=3;
                    else if(by==8)
                        fy+=2;
                    else if(by==9)
                        fy+=1;
                    fx=fx/10;
                    fy=fy/10;
                    while(sh<18){
                        if (mouse_pos == 1 && x_gk>120 && same_direction == true){
                            x_gk-=14;
                            y_gk-=3;
                        }
                        if (mouse_pos == 2 && y_gk>135 && same_direction == true){
                            x_gk-=5;
                            y_gk-=3;
                        }
                        if (mouse_pos == 6 && x_gk>120 && same_direction == true){
                            x_gk-=12;
                            y_gk-=2;
                        }
                        if (mouse_pos == 7 && x_gk>=236 && same_direction == true){
                            x_gk-=6;
                            y_gk-=1;
                        }
                        if (mouse_pos == 11 && x_gk>120 && same_direction == true){
                            x_gk-=13;
                        }
                        if (mouse_pos == 12 && x_gk>=236 && same_direction == true){
                            x_gk-=7;
                        }
                        if (same_direction == false){
                            if (goalkeeper_pos == 1){
                                x_gk-=13;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 2){
                                y_gk-=4;
                            }
                            if (goalkeeper_pos == 3){
                                x_gk+=14;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 4){
                                x_gk-=13;
                                y_gk-=1;
                            }
                            if (goalkeeper_pos == 5){
                                //nothing
                            }
                            if (goalkeeper_pos == 6){
                                x_gk+=14;
                                y_gk-=1;
                            }
                        }
                        if(sh%2==0){
                            x_ball-=fx/2;
                            y_ball-=fy/2;
                        }
                        else{
                            x_ball-=fx;
                            y_ball-=fy;
                        }
                        if(same_direction == true && y_ball-fy<=y && x_ball-fx<=x){
                            print"Result : Player 1 saved the goal";newline;newline;
                            PlaySound(NULL, 0, 0);
                            PlaySound(TEXT("no_goal.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                            SDL_Rect save_rect = { 0, 0, 800, 400};
                            if(choose_team == 1){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, bc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            else if(choose_team == 2){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            else if(choose_team == 3){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mu_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            else{
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, rm_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            sh=18;
                        }
                        else if(same_direction == false && y_ball-fy<=y && x_ball-fx<=x){
                            print"Result : Player 2 scored the goal";newline;newline;
                            results[1]=1;
                            number2++;
                            SDL_Rect score_rect = { 0, 0, 800, 400};
                            SDL_RenderCopy(renderer, score_show, NULL, &score_rect);
                            SDL_Delay(500);
                            SDL_RenderPresent(renderer);
                            SDL_Delay(3000);
                            sh=18;
                        }
                        if(sh>=9)
                            aa-=5*a;
                        else
                            aa-=a;
                        if(h%3==0)
                            a++;
                        sh++;
                        SDL_Rect image_back = { 0, 0, 800, 400 };
                        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                        SDL_RenderPresent(renderer);
                        if (choose_team == 1){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_bc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team == 2){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team == 3){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mu[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else{
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_rm[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
                        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
                        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
                        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
                        if(choose_team == 1){
                            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        if(choose_team == 2){
                            SDL_Rect Man_City_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        if(choose_team == 3){
                            SDL_Rect Man_United_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        if(choose_team == 4){
                            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        if (choose_team_2 == 1){
                            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Rect Man_City_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Rect Man_United_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        else {
                            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        SDL_RenderPresent(renderer);
                        h++;
                        if(h==6)
                            h=1;
                        SDL_Delay(200);
                        if (sh==10){
                            SDL_Delay(200);
                            quit=true;
                        }
                    }
                }
            }
        }
        SDL_RenderPresent(renderer);
        SDL_Rect image_back = { 0, 0, 800, 400 };
        SDL_Rect ball1 = { 370, 320, 75, 75};
        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
        SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
        if (choose_team == 1){
        SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_bc[1]);
        SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
        }
        else if (choose_team == 2){
            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mc[1]);
            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
        }
        else if (choose_team == 3){
            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mu[1]);
            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
        }
        else {
            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_rm[1]);
            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
        }
        if(choose_team == 1){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_bc[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
        }
        if(choose_team == 2){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mc[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Man_City_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
        }
        if(choose_team == 3){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mu[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Man_United_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
        }
        if(choose_team == 4){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_rm[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
        }
        if (choose_team_2 == 1){
            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
        }
        else if (choose_team_2 == 2){
            SDL_Rect Man_City_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
        }
        else if (choose_team_2 == 3){
            SDL_Rect Man_United_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
        }
        else {
            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
        }
        SDL_RenderPresent(renderer);
        if(voice==1){
            PlaySound(TEXT("cheering.wav"), NULL, SND_NOSTOP|SND_ASYNC);
        }
    }



    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    x_ball=370,y_ball=320,fx=0,fy=0,sh=0,h=1,aa=75,a=0;
    x_gk=345,y_gk=200;
    bx=0,by=0;
    x=0,y=0;
    quit = false;
    goal_bool=false;
    first_click_player1=false;
    first_click_player2=false;
    std::cout << "            Turn 3  : Player 1 Is Shooter \n";
    print("Waiting for player 1 to shoot...");
    while (!quit){
        while(SDL_PollEvent(&e) != 0 ){
            if(e.type == SDL_QUIT){
                quit = true;
            }
            else if(e.type == SDL_MOUSEBUTTONDOWN){
                if (first_click_player1==false){
                    first_click_player1=true;
                    for(int i=0;i<32;i++) print"\b";
                    print("Waiting for player 2 to save... ");
                }
                SDL_Rect image_back = { 0, 0, 800, 400 };
                SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                SDL_RenderPresent(renderer);
                PlaySound(NULL, 0, 0);
                PlaySound(TEXT("quite.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                int x,y;
                SDL_GetMouseState( &x, &y );
                keydown = false;
                while (!keydown){
                        PlaySound(NULL, 0, 0);
                        PlaySound(TEXT("quite.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
                        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
                        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
                        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
                        if (choose_team_2 == 1){
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_bc[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mc[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mu[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        else {
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_rm[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        if(choose_team == 1){
                            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        if(choose_team == 2){
                            SDL_Rect Man_City_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        if(choose_team == 3){
                            SDL_Rect Man_United_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        if(choose_team == 4){
                            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        if (choose_team_2 == 1){
                            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Rect Man_City_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Rect Man_United_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        else {
                            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                        SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                        SDL_RenderPresent(renderer);
                    first_click_player2=false;
                    while (SDL_PollEvent(&saver)!=0){
                        SDL_WaitEvent(&saver);
                        if (saver.type == SDL_KEYDOWN){
                            if (saver.key.keysym.sym == SDLK_q){
                                keydown = true;
                                goalkeeper_pos = 1;
                            }
                            else if (saver.key.keysym.sym == SDLK_w){
                                keydown = true;
                                goalkeeper_pos = 2;
                            }
                            else if (saver.key.keysym.sym == SDLK_e){
                                keydown = true;
                                goalkeeper_pos = 3;
                            }
                            else if (saver.key.keysym.sym == SDLK_a){
                                keydown = true;
                                goalkeeper_pos = 4;
                            }
                            else if (saver.key.keysym.sym == SDLK_d){
                                keydown = true;
                                goalkeeper_pos = 6;
                            }
                        else{
                            keydown = true;
                            goalkeeper_pos = 5;
                        }
                            if (first_click_player2==false){
                                first_click_player2=true;
                                for(int i=0;i<32;i++) print"\b";
                                print"Both players had decided... Lets see what happen :)";
                                newline;
                            }
                        }
                    }
                }
                if (x<236 && x>=120 && y<190 && y>=135) mouse_pos = 1;
                else if (x<352 && x>=236 && y<190 && y>=135) mouse_pos = 2;
                else if (x<468 && x>=352 && y<190 && y>=135) mouse_pos = 3;
                else if (x<584 && x>=468 && y<190 && y>=135) mouse_pos = 4;
                else if (x<=700 && x>=584 && y<190 && y>=135) mouse_pos = 5;
                else if (x<236 && x>=120 && y<245 && y>=190) mouse_pos = 6;
                else if (x<352 && x>=236 && y<245 && y>=190) mouse_pos = 7;
                else if (x<468 && x>=352 && y<245 && y>=190) mouse_pos = 8;
                else if (x<584 && x>=468 && y<245 && y>=190) mouse_pos = 9;
                else if (x<=700 && x>=584 && y<245 && y>=190) mouse_pos = 10;
                else if (x<236 && x>=120 && y<=300 && y>=245) mouse_pos = 11;
                else if (x<352 && x>=236 && y<=300 && y>=245) mouse_pos = 12;
                else if (x<468 && x>=352 && y<=300 && y>=245) mouse_pos = 13;
                else if (x<584 && x>=468 && y<=300 && y>=245) mouse_pos = 14;
                else if (x<=700 && x>=584 && y<=300 && y>=245) mouse_pos = 15;
                if (mouse_pos == 1 || mouse_pos == 2) gk_num = 0;
                else if (mouse_pos == 3 || mouse_pos == 8 || mouse_pos == 13) gk_num = 1;
                else if (mouse_pos == 4 || mouse_pos == 5) gk_num = 2;
                else if (mouse_pos == 6) gk_num = 3;
                else if (mouse_pos == 7 || mouse_pos == 12) gk_num = 4;
                else if (mouse_pos == 9 || mouse_pos == 14) gk_num = 5;
                else if (mouse_pos == 10) gk_num = 6;
                else if (mouse_pos == 11) gk_num = 7;
                else if (mouse_pos == 15) gk_num = 8;
                if(gk_num==0){
                    x_chap=125;
                    y_chap=100;
                }
                else if(gk_num==1){
                    x_chap=100;
                    y_chap=125;
                }
                else if(gk_num==2){
                    x_chap=125;
                    y_chap=100;
                }
                else if(gk_num==3){
                    x_chap=150;
                    y_chap=100;
                }
                else if(gk_num==4){
                    x_chap=107;
                    y_chap=110;
                }
                else if(gk_num==5){
                    x_chap=107;
                    y_chap=110;
                }
                else if(gk_num==6){
                    x_chap=150;
                    y_chap=100;
                }
                else if(gk_num==7){
                    x_chap=150;
                    y_chap=100;
                }
                else if(gk_num==8){
                    x_chap=150;
                    y_chap=100;
                }
                same_direction = false;
                if (goalkeeper_pos == 1){
                    if (mouse_pos == 1 || mouse_pos == 2 || mouse_pos == 6 || mouse_pos == 7) same_direction = true;
                }
                else if (goalkeeper_pos == 2){
                    if (mouse_pos == 3 || mouse_pos == 8) same_direction = true;
                }
                else if (goalkeeper_pos == 3){
                    if (mouse_pos == 4 || mouse_pos == 5 || mouse_pos == 9 || mouse_pos == 10) same_direction = true;
                }
                else if (goalkeeper_pos == 4){
                    if (mouse_pos == 11 || mouse_pos == 12) same_direction = true;
                }
                else if (goalkeeper_pos == 5){
                    if (mouse_pos == 8 || mouse_pos == 13) same_direction = true;
                }
                else if (goalkeeper_pos == 6){
                    if (mouse_pos == 14 || mouse_pos == 15) same_direction = true;
                }
                if (same_direction != true){
                    if (goalkeeper_pos==1) gk_num = 0;
                    else if (goalkeeper_pos==2) gk_num = 1;
                    else if (goalkeeper_pos==3) gk_num = 2;
                    else if (goalkeeper_pos==4) gk_num = 3;
                    else if (goalkeeper_pos==5) gk_num = 1;
                    else if (goalkeeper_pos==6) gk_num = 6;
                }
                if(x>=x_ball){
                    fx=x-370;
                    fy=320-y;
                    bx=fx%10;
                    by=fy%10;
                    if(bx==1)
                        fx-=1;
                    else if(bx==2)
                        fx-=2;
                    else if(bx==3)
                        fx-=3;
                    else if(bx==4)
                        fx-=4;
                    else if(bx==5)
                        fx+=5;
                    else if(bx==6)
                        fx+=4;
                    else if(bx==7)
                        fx+=3;
                    else if(bx==8)
                        fx+=2;
                    else if(bx==9)
                        fx+=1;
                    if(by==1)
                        fy-=1;
                    else if(by==2)
                        fy-=2;
                    else if(by==3)
                        fy-=3;
                    else if(by==4)
                        fy-=4;
                    else if(by==5)
                        fy+=5;
                    else if(by==6)
                        fy+=4;
                    else if(by==7)
                        fy+=3;
                    else if(by==8)
                        fy+=2;
                    else if(by==9)
                        fy+=1;
                    fx=fx/10;
                    fy=fy/10;
                    while(sh<18){
                        if (mouse_pos == 3 && y_gk>135 && same_direction == true){
                            y_gk-=4;
                        }
                        if (mouse_pos == 4 && y_gk>135 && same_direction == true){
                            x_gk+=8;
                            y_gk-=3;
                        }
                        if (mouse_pos == 5 && y_gk>135 && same_direction == true){
                            x_gk+=14;
                            y_gk-=3;
                        }
                        if (mouse_pos == 8 && same_direction == true){
                            y_gk-=1;
                        }
                        if (mouse_pos == 9 && x_gk<584 && same_direction == true){
                            x_gk+=7;
                            y_gk-=1;
                        }
                        if (mouse_pos == 10 && x_gk<=600 && same_direction == true){
                            x_gk+=12;
                            y_gk-=2;
                        }
                        if (mouse_pos == 14 && x_gk<=584 && same_direction == true){
                            x_gk+=9;
                        }
                        if (mouse_pos == 15 && x_gk<=600 && same_direction == true){
                            x_gk+=13;
                        }
                        if (same_direction == false){
                            if (goalkeeper_pos == 1){
                                x_gk-=13;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 2){
                                y_gk-=4;
                            }
                            if (goalkeeper_pos == 3){
                                x_gk+=14;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 4){
                                x_gk-=13;
                                y_gk-=1;
                            }
                            if (goalkeeper_pos == 5){
                                //nothing
                            }
                            if (goalkeeper_pos == 6){
                                x_gk+=14;
                                y_gk-=1;
                            }
                        }
                        if (x_gk+30<468 && x_gk+30>=352 && y_gk+10<190 && y_gk+10>=135 && gk_num == 1) gk_pos = 3; // 60 35
                        else if (x_gk+100<584 && x_gk+100>=468 && y_gk+10<190 && y_gk+10>=135 && gk_num == 2) gk_pos = 4; // 170 45
                        else if (x_gk+100<=700 && x_gk+100>=584 && y_gk+10<190 && y_gk+10>=135 && gk_num == 2) gk_pos = 5; // 170 45
                        else if (x_gk+30<468 && x_gk+30>=352 && y_gk+10<245 && y_gk+10>=190 && gk_num == 1) gk_pos = 8; // 60 35
                        else if (x_gk+180<584 && x_gk+180>=468 && y_gk+40<245 && y_gk+40>=190 && gk_num == 5) gk_pos = 9; // 180 80
                        else if (x_gk+170<=700 && x_gk+170>=584 && y_gk+50<245 && y_gk+50>=190 && gk_num == 6) gk_pos = 10; // 210 100
                        else if (x_gk+30<468 && x_gk+30>=352 && y_gk+100<=300 && y_gk+100>=245 && gk_num == 1) gk_pos = 13; // 60 35
                        else if (x_gk+10<584 && x_gk+10>=468 && y_gk+50<=300 && y_gk+50>=245 && gk_num == 5) gk_pos = 14; // 180 80
                        else if (x_gk+200<=700 && x_gk+200>=584 && y_gk+100<=300 && y_gk+100>=245 && gk_num == 8) gk_pos = 15; // 270 140
                        if(sh%2==0){
                            x_ball+=fx/2;
                            y_ball-=fy/2;
                        }
                        else{
                            x_ball+=fx;
                            y_ball-=fy;
                        }
                        if (gk_pos == 9 && mouse_pos == 14) gk_pos=mouse_pos;
                        if (gk_pos == 8 && mouse_pos == 13) gk_pos=mouse_pos;
                        //std::cout<<gk_pos<<"\t"<<mouse_pos<<"\n";
                        if(y_ball-fy<=y && gk_pos==mouse_pos && x_ball-fx<=x && goal_bool==false){
                            print"Result : Player 2 saved the goal";newline;newline;
                            PlaySound(NULL, 0, 0);
                            PlaySound(TEXT("no_goal.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                            SDL_Rect save_rect = { 0, 0, 800, 400};
                            if(choose_team_2 == 1){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, bc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            else if(choose_team_2 == 2){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            else if(choose_team_2 == 3){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mu_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            else{
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, rm_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            sh=18;
                        }
                        else if(same_direction == false && y_ball-fy<=y && x_ball-fx<=x){
                            print"Result : Player 1 scored the goal";newline;newline;
                            results[2]=1;
                            number++;
                            SDL_Rect score_rect = { 0, 0, 800, 400};
                            SDL_RenderCopy(renderer, score_show, NULL, &score_rect);
                            SDL_Delay(500);
                            SDL_RenderPresent(renderer);
                            SDL_Delay(2000);
                            sh=18;
                        }
                        if(sh>=9)
                            aa-=5*a;
                        else
                            aa-=a;
                        if(h%3==0)
                            a++;
                        sh++;
                        SDL_Rect image_back = { 0, 0, 800, 400 };
                        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                        SDL_RenderPresent(renderer);
                        if (choose_team_2 == 1){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_bc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team_2 == 2){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team_2 == 3){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mu[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else{
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_rm[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
                        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
                        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
                        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
                        if(choose_team == 1){
                            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        if(choose_team == 2){
                            SDL_Rect Man_City_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        if(choose_team == 3){
                            SDL_Rect Man_United_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        if(choose_team == 4){
                            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        if (choose_team_2 == 1){
                            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Rect Man_City_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Rect Man_United_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        else {
                            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        SDL_RenderPresent(renderer);
                        h++;
                        if(h==6)
                            h=1;
                        SDL_Delay(200);
                        if (sh==10){
                            SDL_Delay(200);
                            quit=true;
                        }
                    }
                }
                else if(x<x_ball){
                    fx=370-x;
                    fy=320-y;
                    bx=fx%10;
                    by=fy%10;
                    if(bx==1)
                        fx-=1;
                    else if(bx==2)
                        fx-=2;
                    else if(bx==3)
                        fx-=3;
                    else if(bx==4)
                        fx-=4;
                    else if(bx==5)
                        fx+=5;
                    else if(bx==6)
                        fx+=4;
                    else if(bx==7)
                        fx+=3;
                    else if(bx==8)
                        fx+=2;
                    else if(bx==9)
                        fx+=1;
                    if(by==1)
                        fy-=1;
                    else if(by==2)
                        fy-=2;
                    else if(by==3)
                        fy-=3;
                    else if(by==4)
                        fy-=4;
                    else if(by==5)
                        fy+=5;
                    else if(by==6)
                        fy+=4;
                    else if(by==7)
                        fy+=3;
                    else if(by==8)
                        fy+=2;
                    else if(by==9)
                        fy+=1;
                    fx=fx/10;
                    fy=fy/10;
                    while(sh<18){
                        if (mouse_pos == 1 && x_gk>120 && same_direction == true){
                            x_gk-=14;
                            y_gk-=3;
                        }
                        if (mouse_pos == 2 && y_gk>135 && same_direction == true){
                            x_gk-=5;
                            y_gk-=3;
                        }
                        if (mouse_pos == 6 && x_gk>110 && same_direction == true){
                            x_gk-=12;
                            y_gk-=2;
                        }
                        if (mouse_pos == 7 && x_gk>=236 && same_direction == true){
                            x_gk-=6;
                            y_gk-=1;
                        }
                        if (mouse_pos == 11 && x_gk>120 && same_direction == true){
                            x_gk-=13;
                        }
                        if (mouse_pos == 12 && x_gk>=236 && same_direction == true){
                            x_gk-=7;
                        }
                        if (same_direction == false){
                            if (goalkeeper_pos == 1){
                                x_gk-=13;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 2){
                                y_gk-=4;
                            }
                            if (goalkeeper_pos == 3){
                                x_gk+=14;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 4){
                                x_gk-=13;
                                y_gk-=1;
                            }
                            if (goalkeeper_pos == 5){
                                //nothing
                            }
                            if (goalkeeper_pos == 6){
                                x_gk+=14;
                                y_gk-=1;
                            }
                        }
                        if (x_gk+15<236 && x_gk+15>=120 && y_gk+25<190 && y_gk+25>=135 && gk_num == 0) gk_pos = 1;
                        else if (x_gk+15<352 && x_gk+15>=236 && y_gk+15<190 && y_gk+15>=135 && gk_num == 0) gk_pos = 2;
                        else if (x_gk<236 && x_gk>=120 && y_gk+50<245 && y_gk+50>=190 && gk_num == 3) gk_pos = 6; // 15 100
                        else if (x_gk+10<352 && x_gk+10>=236 && y_gk+50<245 && y_gk+50>=190 && gk_num == 4) gk_pos = 7; // 20 80
                        else if (x_gk<236 && x_gk>=120 && y_gk+70<=300 && y_gk+70>=245 && gk_num == 7) gk_pos = 11; // 35 140
                        else if (x_gk+10<352 && x_gk+10>=236 && y_gk+50<=300 && y_gk+50>=245 && gk_num == 4) gk_pos = 12; // 20 80
                        else if (x_gk+30<468 && x_gk+30>=352 && y_gk+200<=300 && y_gk+200>=245 && gk_num == 1) gk_pos = 13; // 60 35
                        if(sh%2==0){
                            x_ball-=fx/2;
                            y_ball-=fy/2;
                        }
                        else{
                            x_ball-=fx;
                            y_ball-=fy;
                        }
                        //std::cout<<gk_pos<<"\t"<<mouse_pos<<"\n";
                        if (gk_pos == 8 && mouse_pos == 13) gk_pos=mouse_pos;
                        if(y_ball-fy<=y && gk_pos==mouse_pos && x_ball-fx<=x && goal_bool==false){
                            print"Result : Player 2 saved the goal";newline;newline;
                            PlaySound(NULL, 0, 0);
                            SDL_Delay(200);
                            PlaySound(TEXT("no_goal.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                            SDL_Rect save_rect = { 0, 0, 800, 400};
                            if(choose_team_2 == 1){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, bc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            else if(choose_team_2 == 2){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            else if(choose_team_2 == 3){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mu_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            else{
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, rm_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            sh=18;
                        }
                        else if(same_direction == false && y_ball-fy<=y && x_ball-fx<=x){
                            print"Result : Player 1 scored the goal";newline;newline;
                            results[2]=1;
                            number++;
                            SDL_Rect score_rect = { 0, 0, 800, 400};
                            SDL_RenderCopy(renderer, score_show, NULL, &score_rect);
                            SDL_Delay(500);
                            SDL_RenderPresent(renderer);
                            SDL_Delay(2000);
                            sh=18;
                        }
                        //std::cout<<number;
                        if(sh>=9)
                            aa-=5*a;
                        else
                            aa-=a;
                        if(h%3==0)
                            a++;
                        sh++;
                        SDL_Rect image_back = { 0, 0, 800, 400 };
                        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                        SDL_RenderPresent(renderer);
                        if (choose_team_2 == 1){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_bc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team_2 == 2){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team_2 == 3){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mu[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else{
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_rm[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
                        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
                        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
                        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
                        if(choose_team == 1){
                            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        if(choose_team == 2){
                            SDL_Rect Man_City_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        if(choose_team == 3){
                            SDL_Rect Man_United_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        if(choose_team == 4){
                            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        if (choose_team_2 == 1){
                            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Rect Man_City_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Rect Man_United_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        else {
                            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        SDL_RenderPresent(renderer);
                        h++;
                        if(h==6)
                            h=1;
                        SDL_Delay(200);
                        if (sh==10){
                            SDL_Delay(200);
                            quit=true;
                        }
                    }
                }
            }
        }
        //SDL_RenderPresent(renderer);
        SDL_Rect image_back = { 0, 0, 800, 400 };
        SDL_Rect ball1 = { 370, 320, 75, 75};
        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
        SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
        if(choose_team == 1){
            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
        }
        if(choose_team == 2){
            SDL_Rect Man_City_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
        }
        if(choose_team == 3){
            SDL_Rect Man_United_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
        }
        if(choose_team == 4){
            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
        }
        if (choose_team_2 == 1){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_bc[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
        }
        else if (choose_team_2 == 2){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mc[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Man_City_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
        }
        else if (choose_team_2 == 3){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mu[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Man_United_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
        }
        else {
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_rm[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
        }
        SDL_RenderPresent(renderer);
        if(voice==1){
            PlaySound(TEXT("cheering.wav"), NULL, SND_NOSTOP|SND_ASYNC);
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    x_ball=370,y_ball=320,fx=0,fy=0,sh=0,h=1,aa=75,a=0;
    x_gk=345,y_gk=200;
    bx=0,by=0;
    x=0,y=0;
    quit = false;
    goal_bool=false;
    first_click_player1=false;
    first_click_player2=false;
    std::cout << "            Turn 4  : Player 2 Is Shooter \n";
    print("Waiting for player 2 to shoot...");
    while (!quit){
        while(SDL_PollEvent(&e) != 0 ){
            if(e.type == SDL_QUIT){
                quit = true;
            }
            else if(e.type == SDL_MOUSEBUTTONDOWN){
                if (first_click_player1==false){
                    first_click_player1=true;
                    for(int i=0;i<32;i++) print"\b";
                    print("Waiting for player 1 to save... ");
                }
                SDL_Rect image_back = { 0, 0, 800, 400 };
                SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                SDL_RenderPresent(renderer);
                int x,y;
                SDL_GetMouseState( &x, &y );
                keydown = false;
                while (!keydown){
                        PlaySound(NULL, 0, 0);
                        PlaySound(TEXT("quite.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
                        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
                        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
                        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
                        if (choose_team == 1){
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_bc[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        else if (choose_team == 2){
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mc[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        else if (choose_team == 3){
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mu[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        else {
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_rm[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        if(choose_team == 1){
                            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        if(choose_team == 2){
                            SDL_Rect Man_City_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        if(choose_team == 3){
                            SDL_Rect Man_United_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        if(choose_team == 4){
                            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        if (choose_team_2 == 1){
                            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Rect Man_City_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Rect Man_United_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        else {
                            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                        SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                        SDL_RenderPresent(renderer);
                    while (SDL_PollEvent(&saver)!=0){
                        SDL_WaitEvent(&saver);
                        if (saver.type == SDL_KEYDOWN){
                            if (saver.key.keysym.sym == SDLK_q){
                                keydown = true;
                                goalkeeper_pos = 1;
                            }
                            else if (saver.key.keysym.sym == SDLK_w){
                                keydown = true;
                                goalkeeper_pos = 2;
                            }
                            else if (saver.key.keysym.sym == SDLK_e){
                                keydown = true;
                                goalkeeper_pos = 3;
                            }
                            else if (saver.key.keysym.sym == SDLK_a){
                                keydown = true;
                                goalkeeper_pos = 4;
                            }
                            else if (saver.key.keysym.sym == SDLK_d){
                                keydown = true;
                                goalkeeper_pos = 6;
                            }
                        else{
                            keydown = true;
                            goalkeeper_pos = 5;
                        }
                        if (first_click_player2==false){
                                first_click_player2=true;
                                for(int i=0;i<32;i++) print"\b";
                                print"Both players had decided... Lets see what happen :)";
                                newline;
                            }
                        }
                    }
                }
                if (x<236 && x>=120 && y<190 && y>=135) mouse_pos = 1;
                else if (x<352 && x>=236 && y<190 && y>=135) mouse_pos = 2;
                else if (x<468 && x>=352 && y<190 && y>=135) mouse_pos = 3;
                else if (x<584 && x>=468 && y<190 && y>=135) mouse_pos = 4;
                else if (x<=700 && x>=584 && y<190 && y>=135) mouse_pos = 5;
                else if (x<236 && x>=120 && y<245 && y>=190) mouse_pos = 6;
                else if (x<352 && x>=236 && y<245 && y>=190) mouse_pos = 7;
                else if (x<468 && x>=352 && y<245 && y>=190) mouse_pos = 8;
                else if (x<584 && x>=468 && y<245 && y>=190) mouse_pos = 9;
                else if (x<=700 && x>=584 && y<245 && y>=190) mouse_pos = 10;
                else if (x<236 && x>=120 && y<=300 && y>=245) mouse_pos = 11;
                else if (x<352 && x>=236 && y<=300 && y>=245) mouse_pos = 12;
                else if (x<468 && x>=352 && y<=300 && y>=245) mouse_pos = 13;
                else if (x<584 && x>=468 && y<=300 && y>=245) mouse_pos = 14;
                else if (x<=700 && x>=584 && y<=300 && y>=245) mouse_pos = 15;
                // 1 6 11 // 2 7 12 // 3 8 13 // 4 9 14 // 5 10 15
                if (mouse_pos == 1 || mouse_pos == 2) gk_num = 0;
                else if (mouse_pos == 3 || mouse_pos == 8 || mouse_pos == 13) gk_num = 1;
                else if (mouse_pos == 4 || mouse_pos == 5) gk_num = 2;
                else if (mouse_pos == 6) gk_num = 3;
                else if (mouse_pos == 7 || mouse_pos == 12) gk_num = 4;
                else if (mouse_pos == 9 || mouse_pos == 14) gk_num = 5;
                else if (mouse_pos == 10) gk_num = 6;
                else if (mouse_pos == 11) gk_num = 7;
                else if (mouse_pos == 15) gk_num = 8;
                if(gk_num==0){
                    x_chap=125;
                    y_chap=100;
                }
                else if(gk_num==1){
                    x_chap=100;
                    y_chap=125;
                }
                else if(gk_num==2){
                    x_chap=125;
                    y_chap=100;
                }
                else if(gk_num==3){
                    x_chap=150;
                    y_chap=100;
                }
                else if(gk_num==4){
                    x_chap=107;
                    y_chap=110;
                }
                else if(gk_num==5){
                    x_chap=107;
                    y_chap=110;
                }
                else if(gk_num==6){
                    x_chap=150;
                    y_chap=100;
                }
                else if(gk_num==7){
                    x_chap=150;
                    y_chap=100;
                }
                else if(gk_num==8){
                    x_chap=150;
                    y_chap=100;
                }
                same_direction = false;
                if (goalkeeper_pos == 1){
                    if (mouse_pos == 1 || mouse_pos == 2 || mouse_pos == 6 || mouse_pos == 7) same_direction = true;
                }
                else if (goalkeeper_pos == 2){
                    if (mouse_pos == 3 || mouse_pos == 8) same_direction = true;
                }
                else if (goalkeeper_pos == 3){
                    if (mouse_pos == 4 || mouse_pos == 5 || mouse_pos == 9 || mouse_pos == 10) same_direction = true;
                }
                else if (goalkeeper_pos == 4){
                    if (mouse_pos == 11 || mouse_pos == 12) same_direction = true;
                }
                else if (goalkeeper_pos == 5){
                    if (mouse_pos == 8 || mouse_pos == 13) same_direction = true;
                }
                else if (goalkeeper_pos == 6){
                    if (mouse_pos == 14 || mouse_pos == 15) same_direction = true;
                }
                if (same_direction != true){
                    if (goalkeeper_pos==1) gk_num = 0;
                    else if (goalkeeper_pos==2) gk_num = 1;
                    else if (goalkeeper_pos==3) gk_num = 2;
                    else if (goalkeeper_pos==4) gk_num = 3;
                    else if (goalkeeper_pos==5) gk_num = 1;
                    else if (goalkeeper_pos==6) gk_num = 6;
                }
                if(x>=x_ball){
                    fx=x-370;
                    fy=320-y;
                    bx=fx%10;
                    by=fy%10;
                    if(bx==1)
                        fx-=1;
                    else if(bx==2)
                        fx-=2;
                    else if(bx==3)
                        fx-=3;
                    else if(bx==4)
                        fx-=4;
                    else if(bx==5)
                        fx+=5;
                    else if(bx==6)
                        fx+=4;
                    else if(bx==7)
                        fx+=3;
                    else if(bx==8)
                        fx+=2;
                    else if(bx==9)
                        fx+=1;
                    if(by==1)
                        fy-=1;
                    else if(by==2)
                        fy-=2;
                    else if(by==3)
                        fy-=3;
                    else if(by==4)
                        fy-=4;
                    else if(by==5)
                        fy+=5;
                    else if(by==6)
                        fy+=4;
                    else if(by==7)
                        fy+=3;
                    else if(by==8)
                        fy+=2;
                    else if(by==9)
                        fy+=1;
                    fx=fx/10;
                    fy=fy/10;
                    while(sh<18){
                        if (mouse_pos == 3 && y_gk>135 && same_direction == true){
                            y_gk-=4;
                        }
                        if (mouse_pos == 4 && y_gk>135 && same_direction == true){
                            x_gk+=8;
                            y_gk-=3;
                        }
                        if (mouse_pos == 5 && y_gk>135 && same_direction == true){
                            x_gk+=14;
                            y_gk-=3;
                        }
                        if (mouse_pos == 8 && same_direction == true){
                            y_gk-=1;
                        }
                        if (mouse_pos == 9 && x_gk<584 && same_direction == true){
                            x_gk+=7;
                            y_gk-=1;
                        }
                        if (mouse_pos == 10 && x_gk<=600 && same_direction == true){
                            x_gk+=12;
                            y_gk-=2;
                        }
                        if (mouse_pos == 14 && x_gk<=584 && same_direction == true){
                            x_gk+=9;
                        }
                        if (mouse_pos == 15 && x_gk<=600 && same_direction == true){
                            x_gk+=13;
                        }
                        if (same_direction == false){
                            if (goalkeeper_pos == 1){
                                x_gk-=13;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 2){
                                y_gk-=4;
                            }
                            if (goalkeeper_pos == 3){
                                x_gk+=14;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 4){
                                x_gk-=13;
                                y_gk-=1;
                            }
                            if (goalkeeper_pos == 5){
                                //nothing
                            }
                            if (goalkeeper_pos == 6){
                                x_gk+=14;
                                y_gk-=1;
                            }
                        }
                        if(sh%2==0){
                            x_ball+=fx/2;
                            y_ball-=fy/2;
                        }
                        else{
                            x_ball+=fx;
                            y_ball-=fy;
                        }
                        if(same_direction == true && y_ball-fy<=y && x_ball-fx<=x){
                            print"Result : Player 1 saved the goal";newline;newline;
                            PlaySound(NULL, 0, 0);
                            PlaySound(TEXT("no_goal.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                            SDL_Rect save_rect = { 0, 0, 800, 400};
                            if(choose_team == 1){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, bc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            else if(choose_team == 2){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            else if(choose_team == 3){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mu_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            else{
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, rm_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            sh=18;
                        }
                        else if(same_direction == false && y_ball-fy<=y && x_ball-fx<=x){
                            print"Result : Player 2 scored the goal";newline;newline;
                            results[3]=1;
                            number2++;
                            SDL_Rect score_rect = { 0, 0, 800, 400};
                            SDL_RenderCopy(renderer, score_show, NULL, &score_rect);
                            SDL_Delay(500);
                            SDL_RenderPresent(renderer);
                            SDL_Delay(2000);
                            sh=18;
                        }
                        if(sh>=9)
                            aa-=5*a;
                        else
                            aa-=a;
                        if(h%3==0)
                            a++;
                        sh++;
                        SDL_Rect image_back = { 0, 0, 800, 400 };
                        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                        SDL_RenderPresent(renderer);
                        if (choose_team == 1){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_bc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team == 2){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team == 3){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mu[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else{
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_rm[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
                        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
                        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
                        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
                        //std::cout<<number2;
                        if(choose_team == 1){
                            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        if(choose_team == 2){
                            SDL_Rect Man_City_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        if(choose_team == 3){
                            SDL_Rect Man_United_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        if(choose_team == 4){
                            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        if (choose_team_2 == 1){
                            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Rect Man_City_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Rect Man_United_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        else {
                            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        SDL_RenderPresent(renderer);
                        h++;
                        if(h==6)
                            h=1;
                        SDL_Delay(200);
                        if (sh==10){
                            SDL_Delay(200);
                            quit = true;
                        }
                    }
                }
                else if(x<x_ball){
                    fx=370-x;
                    fy=320-y;
                    bx=fx%10;
                    by=fy%10;
                    if(bx==1)
                        fx-=1;
                    else if(bx==2)
                        fx-=2;
                    else if(bx==3)
                        fx-=3;
                    else if(bx==4)
                        fx-=4;
                    else if(bx==5)
                        fx+=5;
                    else if(bx==6)
                        fx+=4;
                    else if(bx==7)
                        fx+=3;
                    else if(bx==8)
                        fx+=2;
                    else if(bx==9)
                        fx+=1;
                    if(by==1)
                        fy-=1;
                    else if(by==2)
                        fy-=2;
                    else if(by==3)
                        fy-=3;
                    else if(by==4)
                        fy-=4;
                    else if(by==5)
                        fy+=5;
                    else if(by==6)
                        fy+=4;
                    else if(by==7)
                        fy+=3;
                    else if(by==8)
                        fy+=2;
                    else if(by==9)
                        fy+=1;
                    fx=fx/10;
                    fy=fy/10;
                    while(sh<18){
                        if (mouse_pos == 1 && x_gk>120 && same_direction == true){
                            x_gk-=14;
                            y_gk-=3;
                        }
                        if (mouse_pos == 2 && y_gk>135 && same_direction == true){
                            x_gk-=5;
                            y_gk-=3;
                        }
                        if (mouse_pos == 6 && x_gk>120 && same_direction == true){
                            x_gk-=12;
                            y_gk-=2;
                        }
                        if (mouse_pos == 7 && x_gk>=236 && same_direction == true){
                            x_gk-=6;
                            y_gk-=1;
                        }
                        if (mouse_pos == 11 && x_gk>120 && same_direction == true){
                            x_gk-=13;
                        }
                        if (mouse_pos == 12 && x_gk>=236 && same_direction == true){
                            x_gk-=7;
                        }
                        if (same_direction == false){
                            if (goalkeeper_pos == 1){
                                x_gk-=13;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 2){
                                y_gk-=4;
                            }
                            if (goalkeeper_pos == 3){
                                x_gk+=14;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 4){
                                x_gk-=13;
                                y_gk-=1;
                            }
                            if (goalkeeper_pos == 5){
                                //nothing
                            }
                            if (goalkeeper_pos == 6){
                                x_gk+=14;
                                y_gk-=1;
                            }
                        }
                        if(sh%2==0){
                            x_ball-=fx/2;
                            y_ball-=fy/2;
                        }
                        else{
                            x_ball-=fx;
                            y_ball-=fy;
                        }
                        if(same_direction == true && y_ball-fy<=y && x_ball-fx<=x){
                            print"Result : Player 1 saved the goal";newline;newline;
                            PlaySound(NULL, 0, 0);
                            PlaySound(TEXT("no_goal.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                            SDL_Rect save_rect = { 0, 0, 800, 400};
                            if(choose_team == 1){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, bc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            else if(choose_team == 2){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            else if(choose_team == 3){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mu_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            else{
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, rm_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            sh=18;
                        }
                        else if(same_direction == false && y_ball-fy<=y && x_ball-fx<=x){
                            print"Result : Player 2 scored the goal";newline;newline;
                            results[3]=1;
                            number2++;
                            SDL_Rect score_rect = { 0, 0, 800, 400};
                            SDL_RenderCopy(renderer, score_show, NULL, &score_rect);
                            SDL_Delay(500);
                            SDL_RenderPresent(renderer);
                            SDL_Delay(3000);
                            sh=18;
                        }
                        if(sh>=9)
                            aa-=5*a;
                        else
                            aa-=a;
                        if(h%3==0)
                            a++;
                        sh++;
                        SDL_Rect image_back = { 0, 0, 800, 400 };
                        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                        SDL_RenderPresent(renderer);
                        if (choose_team == 1){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_bc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team == 2){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team == 3){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mu[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else{
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_rm[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
                        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
                        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
                        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
                        if(choose_team == 1){
                            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        if(choose_team == 2){
                            SDL_Rect Man_City_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        if(choose_team == 3){
                            SDL_Rect Man_United_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        if(choose_team == 4){
                            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        if (choose_team_2 == 1){
                            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Rect Man_City_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Rect Man_United_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        else {
                            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        SDL_RenderPresent(renderer);
                        h++;
                        if(h==6)
                            h=1;
                        SDL_Delay(200);
                        if (sh==10){
                            SDL_Delay(200);
                            quit=true;
                        }
                    }
                }
            }
        }
        SDL_RenderPresent(renderer);
        SDL_Rect image_back = { 0, 0, 800, 400 };
        SDL_Rect ball1 = { 370, 320, 75, 75};
        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
        SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
        if (choose_team == 1){
        SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_bc[1]);
        SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
        }
        else if (choose_team == 2){
            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mc[1]);
            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
        }
        else if (choose_team == 3){
            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mu[1]);
            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
        }
        else {
            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_rm[1]);
            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
        }
        if(choose_team == 1){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_bc[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
        }
        if(choose_team == 2){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mc[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Man_City_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
        }
        if(choose_team == 3){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mu[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Man_United_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
        }
        if(choose_team == 4){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_rm[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
        }
        if (choose_team_2 == 1){
            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
        }
        else if (choose_team_2 == 2){
            SDL_Rect Man_City_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
        }
        else if (choose_team_2 == 3){
            SDL_Rect Man_United_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
        }
        else {
            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
        }
        SDL_RenderPresent(renderer);
        if(voice==1){
            PlaySound(TEXT("cheering.wav"), NULL, SND_NOSTOP|SND_ASYNC);
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    x_ball=370,y_ball=320,fx=0,fy=0,sh=0,h=1,aa=75,a=0;
    x_gk=345,y_gk=200;
    bx=0,by=0;
    x=0,y=0;
    quit = false;
    goal_bool=false;
    first_click_player1=false;
    first_click_player2=false;
    std::cout << "            Turn 5  : Player 1 Is Shooter \n";
    print("Waiting for player 1 to shoot...");
    while (!quit){
        while(SDL_PollEvent(&e) != 0 ){
            if(e.type == SDL_QUIT){
                quit = true;
            }
            else if(e.type == SDL_MOUSEBUTTONDOWN){
                if (first_click_player1==false){
                    first_click_player1=true;
                    for(int i=0;i<32;i++) print"\b";
                    print("Waiting for player 2 to save... ");
                }
                SDL_Rect image_back = { 0, 0, 800, 400 };
                SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                SDL_RenderPresent(renderer);
                PlaySound(NULL, 0, 0);
                PlaySound(TEXT("quite.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                int x,y;
                SDL_GetMouseState( &x, &y );
                keydown = false;
                while (!keydown){
                        PlaySound(NULL, 0, 0);
                        PlaySound(TEXT("quite.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
                        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
                        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
                        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
                        if (choose_team_2 == 1){
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_bc[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mc[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mu[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        else {
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_rm[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        if(choose_team == 1){
                            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        if(choose_team == 2){
                            SDL_Rect Man_City_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        if(choose_team == 3){
                            SDL_Rect Man_United_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        if(choose_team == 4){
                            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        if (choose_team_2 == 1){
                            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Rect Man_City_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Rect Man_United_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        else {
                            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                        SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                        SDL_RenderPresent(renderer);
                    first_click_player2=false;
                    while (SDL_PollEvent(&saver)!=0){
                        SDL_WaitEvent(&saver);
                        if (saver.type == SDL_KEYDOWN){
                            if (saver.key.keysym.sym == SDLK_q){
                                keydown = true;
                                goalkeeper_pos = 1;
                            }
                            else if (saver.key.keysym.sym == SDLK_w){
                                keydown = true;
                                goalkeeper_pos = 2;
                            }
                            else if (saver.key.keysym.sym == SDLK_e){
                                keydown = true;
                                goalkeeper_pos = 3;
                            }
                            else if (saver.key.keysym.sym == SDLK_a){
                                keydown = true;
                                goalkeeper_pos = 4;
                            }
                            else if (saver.key.keysym.sym == SDLK_d){
                                keydown = true;
                                goalkeeper_pos = 6;
                            }
                        else{
                            keydown = true;
                            goalkeeper_pos = 5;
                        }
                            if (first_click_player2==false){
                                first_click_player2=true;
                                for(int i=0;i<32;i++) print"\b";
                                print"Both players had decided... Lets see what happen :)";
                                newline;
                            }
                        }
                    }
                }
                if (x<236 && x>=120 && y<190 && y>=135) mouse_pos = 1;
                else if (x<352 && x>=236 && y<190 && y>=135) mouse_pos = 2;
                else if (x<468 && x>=352 && y<190 && y>=135) mouse_pos = 3;
                else if (x<584 && x>=468 && y<190 && y>=135) mouse_pos = 4;
                else if (x<=700 && x>=584 && y<190 && y>=135) mouse_pos = 5;
                else if (x<236 && x>=120 && y<245 && y>=190) mouse_pos = 6;
                else if (x<352 && x>=236 && y<245 && y>=190) mouse_pos = 7;
                else if (x<468 && x>=352 && y<245 && y>=190) mouse_pos = 8;
                else if (x<584 && x>=468 && y<245 && y>=190) mouse_pos = 9;
                else if (x<=700 && x>=584 && y<245 && y>=190) mouse_pos = 10;
                else if (x<236 && x>=120 && y<=300 && y>=245) mouse_pos = 11;
                else if (x<352 && x>=236 && y<=300 && y>=245) mouse_pos = 12;
                else if (x<468 && x>=352 && y<=300 && y>=245) mouse_pos = 13;
                else if (x<584 && x>=468 && y<=300 && y>=245) mouse_pos = 14;
                else if (x<=700 && x>=584 && y<=300 && y>=245) mouse_pos = 15;
                if (mouse_pos == 1 || mouse_pos == 2) gk_num = 0;
                else if (mouse_pos == 3 || mouse_pos == 8 || mouse_pos == 13) gk_num = 1;
                else if (mouse_pos == 4 || mouse_pos == 5) gk_num = 2;
                else if (mouse_pos == 6) gk_num = 3;
                else if (mouse_pos == 7 || mouse_pos == 12) gk_num = 4;
                else if (mouse_pos == 9 || mouse_pos == 14) gk_num = 5;
                else if (mouse_pos == 10) gk_num = 6;
                else if (mouse_pos == 11) gk_num = 7;
                else if (mouse_pos == 15) gk_num = 8;
                if(gk_num==0){
                    x_chap=125;
                    y_chap=100;
                }
                else if(gk_num==1){
                    x_chap=100;
                    y_chap=125;
                }
                else if(gk_num==2){
                    x_chap=125;
                    y_chap=100;
                }
                else if(gk_num==3){
                    x_chap=150;
                    y_chap=100;
                }
                else if(gk_num==4){
                    x_chap=107;
                    y_chap=110;
                }
                else if(gk_num==5){
                    x_chap=107;
                    y_chap=110;
                }
                else if(gk_num==6){
                    x_chap=150;
                    y_chap=100;
                }
                else if(gk_num==7){
                    x_chap=150;
                    y_chap=100;
                }
                else if(gk_num==8){
                    x_chap=150;
                    y_chap=100;
                }
                same_direction = false;
                if (goalkeeper_pos == 1){
                    if (mouse_pos == 1 || mouse_pos == 2 || mouse_pos == 6 || mouse_pos == 7) same_direction = true;
                }
                else if (goalkeeper_pos == 2){
                    if (mouse_pos == 3 || mouse_pos == 8) same_direction = true;
                }
                else if (goalkeeper_pos == 3){
                    if (mouse_pos == 4 || mouse_pos == 5 || mouse_pos == 9 || mouse_pos == 10) same_direction = true;
                }
                else if (goalkeeper_pos == 4){
                    if (mouse_pos == 11 || mouse_pos == 12) same_direction = true;
                }
                else if (goalkeeper_pos == 5){
                    if (mouse_pos == 8 || mouse_pos == 13) same_direction = true;
                }
                else if (goalkeeper_pos == 6){
                    if (mouse_pos == 14 || mouse_pos == 15) same_direction = true;
                }
                if (same_direction != true){
                    if (goalkeeper_pos==1) gk_num = 0;
                    else if (goalkeeper_pos==2) gk_num = 1;
                    else if (goalkeeper_pos==3) gk_num = 2;
                    else if (goalkeeper_pos==4) gk_num = 3;
                    else if (goalkeeper_pos==5) gk_num = 1;
                    else if (goalkeeper_pos==6) gk_num = 6;
                }
                if(x>=x_ball){
                    fx=x-370;
                    fy=320-y;
                    bx=fx%10;
                    by=fy%10;
                    if(bx==1)
                        fx-=1;
                    else if(bx==2)
                        fx-=2;
                    else if(bx==3)
                        fx-=3;
                    else if(bx==4)
                        fx-=4;
                    else if(bx==5)
                        fx+=5;
                    else if(bx==6)
                        fx+=4;
                    else if(bx==7)
                        fx+=3;
                    else if(bx==8)
                        fx+=2;
                    else if(bx==9)
                        fx+=1;
                    if(by==1)
                        fy-=1;
                    else if(by==2)
                        fy-=2;
                    else if(by==3)
                        fy-=3;
                    else if(by==4)
                        fy-=4;
                    else if(by==5)
                        fy+=5;
                    else if(by==6)
                        fy+=4;
                    else if(by==7)
                        fy+=3;
                    else if(by==8)
                        fy+=2;
                    else if(by==9)
                        fy+=1;
                    fx=fx/10;
                    fy=fy/10;
                    while(sh<18){
                        if (mouse_pos == 3 && y_gk>135 && same_direction == true){
                            y_gk-=4;
                        }
                        if (mouse_pos == 4 && y_gk>135 && same_direction == true){
                            x_gk+=8;
                            y_gk-=3;
                        }
                        if (mouse_pos == 5 && y_gk>135 && same_direction == true){
                            x_gk+=14;
                            y_gk-=3;
                        }
                        if (mouse_pos == 8 && same_direction == true){
                            y_gk-=1;
                        }
                        if (mouse_pos == 9 && x_gk<584 && same_direction == true){
                            x_gk+=7;
                            y_gk-=1;
                        }
                        if (mouse_pos == 10 && x_gk<=600 && same_direction == true){
                            x_gk+=12;
                            y_gk-=2;
                        }
                        if (mouse_pos == 14 && x_gk<=584 && same_direction == true){
                            x_gk+=9;
                        }
                        if (mouse_pos == 15 && x_gk<=600 && same_direction == true){
                            x_gk+=13;
                        }
                        if (same_direction == false){
                            if (goalkeeper_pos == 1){
                                x_gk-=13;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 2){
                                y_gk-=4;
                            }
                            if (goalkeeper_pos == 3){
                                x_gk+=14;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 4){
                                x_gk-=13;
                                y_gk-=1;
                            }
                            if (goalkeeper_pos == 5){
                                //nothing
                            }
                            if (goalkeeper_pos == 6){
                                x_gk+=14;
                                y_gk-=1;
                            }
                        }
                        if (x_gk+30<468 && x_gk+30>=352 && y_gk+10<190 && y_gk+10>=135 && gk_num == 1) gk_pos = 3; // 60 35
                        else if (x_gk+100<584 && x_gk+100>=468 && y_gk+10<190 && y_gk+10>=135 && gk_num == 2) gk_pos = 4; // 170 45
                        else if (x_gk+100<=700 && x_gk+100>=584 && y_gk+10<190 && y_gk+10>=135 && gk_num == 2) gk_pos = 5; // 170 45
                        else if (x_gk+30<468 && x_gk+30>=352 && y_gk+10<245 && y_gk+10>=190 && gk_num == 1) gk_pos = 8; // 60 35
                        else if (x_gk+180<584 && x_gk+180>=468 && y_gk+40<245 && y_gk+40>=190 && gk_num == 5) gk_pos = 9; // 180 80
                        else if (x_gk+170<=700 && x_gk+170>=584 && y_gk+50<245 && y_gk+50>=190 && gk_num == 6) gk_pos = 10; // 210 100
                        else if (x_gk+30<468 && x_gk+30>=352 && y_gk+100<=300 && y_gk+100>=245 && gk_num == 1) gk_pos = 13; // 60 35
                        else if (x_gk+10<584 && x_gk+10>=468 && y_gk+50<=300 && y_gk+50>=245 && gk_num == 5) gk_pos = 14; // 180 80
                        else if (x_gk+200<=700 && x_gk+200>=584 && y_gk+100<=300 && y_gk+100>=245 && gk_num == 8) gk_pos = 15; // 270 140
                        if(sh%2==0){
                            x_ball+=fx/2;
                            y_ball-=fy/2;
                        }
                        else{
                            x_ball+=fx;
                            y_ball-=fy;
                        }
                        if (gk_pos == 9 && mouse_pos == 14) gk_pos=mouse_pos;
                        if (gk_pos == 8 && mouse_pos == 13) gk_pos=mouse_pos;
                        //std::cout<<gk_pos<<"\t"<<mouse_pos<<"\n";
                        if(y_ball-fy<=y && gk_pos==mouse_pos && x_ball-fx<=x && goal_bool==false){
                            print"Result : Player 2 saved the goal";newline;newline;
                            PlaySound(NULL, 0, 0);
                            PlaySound(TEXT("no_goal.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                            SDL_Rect save_rect = { 0, 0, 800, 400};
                            if(choose_team_2 == 1){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, bc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            else if(choose_team_2 == 2){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            else if(choose_team_2 == 3){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mu_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            else{
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, rm_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            sh=18;
                        }
                        else if(same_direction == false && y_ball-fy<=y && x_ball-fx<=x){
                            print"Result : Player 1 scored the goal";newline;newline;
                            results[4]=1;
                            number++;
                            SDL_Rect score_rect = { 0, 0, 800, 400};
                            SDL_RenderCopy(renderer, score_show, NULL, &score_rect);
                            SDL_Delay(500);
                            SDL_RenderPresent(renderer);
                            SDL_Delay(2000);
                            sh=18;
                        }
                        if(sh>=9)
                            aa-=5*a;
                        else
                            aa-=a;
                        if(h%3==0)
                            a++;
                        sh++;
                        SDL_Rect image_back = { 0, 0, 800, 400 };
                        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                        SDL_RenderPresent(renderer);
                        if (choose_team_2 == 1){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_bc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team_2 == 2){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team_2 == 3){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mu[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else{
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_rm[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
                        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
                        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
                        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
                        if(choose_team == 1){
                            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        if(choose_team == 2){
                            SDL_Rect Man_City_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        if(choose_team == 3){
                            SDL_Rect Man_United_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        if(choose_team == 4){
                            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        if (choose_team_2 == 1){
                            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Rect Man_City_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Rect Man_United_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        else {
                            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        SDL_RenderPresent(renderer);
                        h++;
                        if(h==6)
                            h=1;
                        SDL_Delay(200);
                        if (sh==10){
                            SDL_Delay(200);
                            quit=true;
                        }
                    }
                }
                else if(x<x_ball){
                    fx=370-x;
                    fy=320-y;
                    bx=fx%10;
                    by=fy%10;
                    if(bx==1)
                        fx-=1;
                    else if(bx==2)
                        fx-=2;
                    else if(bx==3)
                        fx-=3;
                    else if(bx==4)
                        fx-=4;
                    else if(bx==5)
                        fx+=5;
                    else if(bx==6)
                        fx+=4;
                    else if(bx==7)
                        fx+=3;
                    else if(bx==8)
                        fx+=2;
                    else if(bx==9)
                        fx+=1;
                    if(by==1)
                        fy-=1;
                    else if(by==2)
                        fy-=2;
                    else if(by==3)
                        fy-=3;
                    else if(by==4)
                        fy-=4;
                    else if(by==5)
                        fy+=5;
                    else if(by==6)
                        fy+=4;
                    else if(by==7)
                        fy+=3;
                    else if(by==8)
                        fy+=2;
                    else if(by==9)
                        fy+=1;
                    fx=fx/10;
                    fy=fy/10;
                    while(sh<18){
                        if (mouse_pos == 1 && x_gk>120 && same_direction == true){
                            x_gk-=14;
                            y_gk-=3;
                        }
                        if (mouse_pos == 2 && y_gk>135 && same_direction == true){
                            x_gk-=5;
                            y_gk-=3;
                        }
                        if (mouse_pos == 6 && x_gk>110 && same_direction == true){
                            x_gk-=12;
                            y_gk-=2;
                        }
                        if (mouse_pos == 7 && x_gk>=236 && same_direction == true){
                            x_gk-=6;
                            y_gk-=1;
                        }
                        if (mouse_pos == 11 && x_gk>120 && same_direction == true){
                            x_gk-=13;
                        }
                        if (mouse_pos == 12 && x_gk>=236 && same_direction == true){
                            x_gk-=7;
                        }
                        if (same_direction == false){
                            if (goalkeeper_pos == 1){
                                x_gk-=13;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 2){
                                y_gk-=4;
                            }
                            if (goalkeeper_pos == 3){
                                x_gk+=14;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 4){
                                x_gk-=13;
                                y_gk-=1;
                            }
                            if (goalkeeper_pos == 5){
                                //nothing
                            }
                            if (goalkeeper_pos == 6){
                                x_gk+=14;
                                y_gk-=1;
                            }
                        }
                        if (x_gk+15<236 && x_gk+15>=120 && y_gk+25<190 && y_gk+25>=135 && gk_num == 0) gk_pos = 1;
                        else if (x_gk+15<352 && x_gk+15>=236 && y_gk+15<190 && y_gk+15>=135 && gk_num == 0) gk_pos = 2;
                        else if (x_gk<236 && x_gk>=120 && y_gk+50<245 && y_gk+50>=190 && gk_num == 3) gk_pos = 6; // 15 100
                        else if (x_gk+10<352 && x_gk+10>=236 && y_gk+50<245 && y_gk+50>=190 && gk_num == 4) gk_pos = 7; // 20 80
                        else if (x_gk<236 && x_gk>=120 && y_gk+70<=300 && y_gk+70>=245 && gk_num == 7) gk_pos = 11; // 35 140
                        else if (x_gk+10<352 && x_gk+10>=236 && y_gk+50<=300 && y_gk+50>=245 && gk_num == 4) gk_pos = 12; // 20 80
                        else if (x_gk+30<468 && x_gk+30>=352 && y_gk+200<=300 && y_gk+200>=245 && gk_num == 1) gk_pos = 13; // 60 35
                        if(sh%2==0){
                            x_ball-=fx/2;
                            y_ball-=fy/2;
                        }
                        else{
                            x_ball-=fx;
                            y_ball-=fy;
                        }
                        //std::cout<<gk_pos<<"\t"<<mouse_pos<<"\n";
                        if (gk_pos == 8 && mouse_pos == 13) gk_pos=mouse_pos;
                        if(y_ball-fy<=y && gk_pos==mouse_pos && x_ball-fx<=x && goal_bool==false){
                            print"Result : Player 2 saved the goal";newline;newline;
                            PlaySound(NULL, 0, 0);
                            SDL_Delay(200);
                            PlaySound(TEXT("no_goal.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                            SDL_Rect save_rect = { 0, 0, 800, 400};
                            if(choose_team_2 == 1){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, bc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            else if(choose_team_2 == 2){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            else if(choose_team_2 == 3){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mu_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            else{
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, rm_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            sh=18;
                        }
                        else if(same_direction == false && y_ball-fy<=y && x_ball-fx<=x){
                            print"Result : Player 1 scored the goal";newline;newline;
                            results[4]=1;
                            number++;
                            SDL_Rect score_rect = { 0, 0, 800, 400};
                            SDL_RenderCopy(renderer, score_show, NULL, &score_rect);
                            SDL_Delay(500);
                            SDL_RenderPresent(renderer);
                            SDL_Delay(2000);
                            sh=18;
                        }
                        //std::cout<<number;
                        if(sh>=9)
                            aa-=5*a;
                        else
                            aa-=a;
                        if(h%3==0)
                            a++;
                        sh++;
                        SDL_Rect image_back = { 0, 0, 800, 400 };
                        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                        SDL_RenderPresent(renderer);
                        if (choose_team_2 == 1){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_bc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team_2 == 2){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team_2 == 3){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mu[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else{
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_rm[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
                        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
                        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
                        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
                        if(choose_team == 1){
                            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        if(choose_team == 2){
                            SDL_Rect Man_City_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        if(choose_team == 3){
                            SDL_Rect Man_United_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        if(choose_team == 4){
                            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        if (choose_team_2 == 1){
                            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Rect Man_City_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Rect Man_United_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        else {
                            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        SDL_RenderPresent(renderer);
                        h++;
                        if(h==6)
                            h=1;
                        SDL_Delay(200);
                        if (sh==10){
                            SDL_Delay(200);
                            quit=true;
                        }
                    }
                }
            }
        }
        //SDL_RenderPresent(renderer);
        SDL_Rect image_back = { 0, 0, 800, 400 };
        SDL_Rect ball1 = { 370, 320, 75, 75};
        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
        SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
        if(choose_team == 1){
            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
        }
        if(choose_team == 2){
            SDL_Rect Man_City_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
        }
        if(choose_team == 3){
            SDL_Rect Man_United_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
        }
        if(choose_team == 4){
            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
        }
        if (choose_team_2 == 1){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_bc[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
        }
        else if (choose_team_2 == 2){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mc[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Man_City_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
        }
        else if (choose_team_2 == 3){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mu[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Man_United_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
        }
        else {
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_rm[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
        }
        SDL_RenderPresent(renderer);
        if(voice==1){
            PlaySound(TEXT("cheering.wav"), NULL, SND_NOSTOP|SND_ASYNC);
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    x_ball=370,y_ball=320,fx=0,fy=0,sh=0,h=1,aa=75,a=0;
    x_gk=345,y_gk=200;
    bx=0,by=0;
    x=0,y=0;
    quit = false;
    goal_bool=false;
    first_click_player1=false;
    first_click_player2=false;
    std::cout << "            Turn 6  : Player 2 Is Shooter \n";
    print("Waiting for player 2 to shoot...");
    while (!quit){
        while(SDL_PollEvent(&e) != 0 ){
            if(e.type == SDL_QUIT){
                quit = true;
            }
            else if(e.type == SDL_MOUSEBUTTONDOWN){
                if (first_click_player1==false){
                    first_click_player1=true;
                    for(int i=0;i<32;i++) print"\b";
                    print("Waiting for player 1 to save... ");
                }
                SDL_Rect image_back = { 0, 0, 800, 400 };
                SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                SDL_RenderPresent(renderer);
                int x,y;
                SDL_GetMouseState( &x, &y );
                keydown = false;
                while (!keydown){
                        PlaySound(NULL, 0, 0);
                        PlaySound(TEXT("quite.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
                        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
                        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
                        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
                        if (choose_team == 1){
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_bc[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        else if (choose_team == 2){
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mc[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        else if (choose_team == 3){
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mu[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        else {
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_rm[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        if(choose_team == 1){
                            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        if(choose_team == 2){
                            SDL_Rect Man_City_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        if(choose_team == 3){
                            SDL_Rect Man_United_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        if(choose_team == 4){
                            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        if (choose_team_2 == 1){
                            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Rect Man_City_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Rect Man_United_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        else {
                            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                        SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                        SDL_RenderPresent(renderer);
                    while (SDL_PollEvent(&saver)!=0){
                        SDL_WaitEvent(&saver);
                        if (saver.type == SDL_KEYDOWN){
                            if (saver.key.keysym.sym == SDLK_q){
                                keydown = true;
                                goalkeeper_pos = 1;
                            }
                            else if (saver.key.keysym.sym == SDLK_w){
                                keydown = true;
                                goalkeeper_pos = 2;
                            }
                            else if (saver.key.keysym.sym == SDLK_e){
                                keydown = true;
                                goalkeeper_pos = 3;
                            }
                            else if (saver.key.keysym.sym == SDLK_a){
                                keydown = true;
                                goalkeeper_pos = 4;
                            }
                            else if (saver.key.keysym.sym == SDLK_d){
                                keydown = true;
                                goalkeeper_pos = 6;
                            }
                        else{
                            keydown = true;
                            goalkeeper_pos = 5;
                        }
                        if (first_click_player2==false){
                                first_click_player2=true;
                                for(int i=0;i<32;i++) print"\b";
                                print"Both players had decided... Lets see what happen :)";
                                newline;
                            }
                        }
                    }
                }
                if (x<236 && x>=120 && y<190 && y>=135) mouse_pos = 1;
                else if (x<352 && x>=236 && y<190 && y>=135) mouse_pos = 2;
                else if (x<468 && x>=352 && y<190 && y>=135) mouse_pos = 3;
                else if (x<584 && x>=468 && y<190 && y>=135) mouse_pos = 4;
                else if (x<=700 && x>=584 && y<190 && y>=135) mouse_pos = 5;
                else if (x<236 && x>=120 && y<245 && y>=190) mouse_pos = 6;
                else if (x<352 && x>=236 && y<245 && y>=190) mouse_pos = 7;
                else if (x<468 && x>=352 && y<245 && y>=190) mouse_pos = 8;
                else if (x<584 && x>=468 && y<245 && y>=190) mouse_pos = 9;
                else if (x<=700 && x>=584 && y<245 && y>=190) mouse_pos = 10;
                else if (x<236 && x>=120 && y<=300 && y>=245) mouse_pos = 11;
                else if (x<352 && x>=236 && y<=300 && y>=245) mouse_pos = 12;
                else if (x<468 && x>=352 && y<=300 && y>=245) mouse_pos = 13;
                else if (x<584 && x>=468 && y<=300 && y>=245) mouse_pos = 14;
                else if (x<=700 && x>=584 && y<=300 && y>=245) mouse_pos = 15;
                // 1 6 11 // 2 7 12 // 3 8 13 // 4 9 14 // 5 10 15
                if (mouse_pos == 1 || mouse_pos == 2) gk_num = 0;
                else if (mouse_pos == 3 || mouse_pos == 8 || mouse_pos == 13) gk_num = 1;
                else if (mouse_pos == 4 || mouse_pos == 5) gk_num = 2;
                else if (mouse_pos == 6) gk_num = 3;
                else if (mouse_pos == 7 || mouse_pos == 12) gk_num = 4;
                else if (mouse_pos == 9 || mouse_pos == 14) gk_num = 5;
                else if (mouse_pos == 10) gk_num = 6;
                else if (mouse_pos == 11) gk_num = 7;
                else if (mouse_pos == 15) gk_num = 8;
                if(gk_num==0){
                    x_chap=125;
                    y_chap=100;
                }
                else if(gk_num==1){
                    x_chap=100;
                    y_chap=125;
                }
                else if(gk_num==2){
                    x_chap=125;
                    y_chap=100;
                }
                else if(gk_num==3){
                    x_chap=150;
                    y_chap=100;
                }
                else if(gk_num==4){
                    x_chap=107;
                    y_chap=110;
                }
                else if(gk_num==5){
                    x_chap=107;
                    y_chap=110;
                }
                else if(gk_num==6){
                    x_chap=150;
                    y_chap=100;
                }
                else if(gk_num==7){
                    x_chap=150;
                    y_chap=100;
                }
                else if(gk_num==8){
                    x_chap=150;
                    y_chap=100;
                }
                same_direction = false;
                if (goalkeeper_pos == 1){
                    if (mouse_pos == 1 || mouse_pos == 2 || mouse_pos == 6 || mouse_pos == 7) same_direction = true;
                }
                else if (goalkeeper_pos == 2){
                    if (mouse_pos == 3 || mouse_pos == 8) same_direction = true;
                }
                else if (goalkeeper_pos == 3){
                    if (mouse_pos == 4 || mouse_pos == 5 || mouse_pos == 9 || mouse_pos == 10) same_direction = true;
                }
                else if (goalkeeper_pos == 4){
                    if (mouse_pos == 11 || mouse_pos == 12) same_direction = true;
                }
                else if (goalkeeper_pos == 5){
                    if (mouse_pos == 8 || mouse_pos == 13) same_direction = true;
                }
                else if (goalkeeper_pos == 6){
                    if (mouse_pos == 14 || mouse_pos == 15) same_direction = true;
                }
                if (same_direction != true){
                    if (goalkeeper_pos==1) gk_num = 0;
                    else if (goalkeeper_pos==2) gk_num = 1;
                    else if (goalkeeper_pos==3) gk_num = 2;
                    else if (goalkeeper_pos==4) gk_num = 3;
                    else if (goalkeeper_pos==5) gk_num = 1;
                    else if (goalkeeper_pos==6) gk_num = 6;
                }
                if(x>=x_ball){
                    fx=x-370;
                    fy=320-y;
                    bx=fx%10;
                    by=fy%10;
                    if(bx==1)
                        fx-=1;
                    else if(bx==2)
                        fx-=2;
                    else if(bx==3)
                        fx-=3;
                    else if(bx==4)
                        fx-=4;
                    else if(bx==5)
                        fx+=5;
                    else if(bx==6)
                        fx+=4;
                    else if(bx==7)
                        fx+=3;
                    else if(bx==8)
                        fx+=2;
                    else if(bx==9)
                        fx+=1;
                    if(by==1)
                        fy-=1;
                    else if(by==2)
                        fy-=2;
                    else if(by==3)
                        fy-=3;
                    else if(by==4)
                        fy-=4;
                    else if(by==5)
                        fy+=5;
                    else if(by==6)
                        fy+=4;
                    else if(by==7)
                        fy+=3;
                    else if(by==8)
                        fy+=2;
                    else if(by==9)
                        fy+=1;
                    fx=fx/10;
                    fy=fy/10;
                    while(sh<18){
                        if (mouse_pos == 3 && y_gk>135 && same_direction == true){
                            y_gk-=4;
                        }
                        if (mouse_pos == 4 && y_gk>135 && same_direction == true){
                            x_gk+=8;
                            y_gk-=3;
                        }
                        if (mouse_pos == 5 && y_gk>135 && same_direction == true){
                            x_gk+=14;
                            y_gk-=3;
                        }
                        if (mouse_pos == 8 && same_direction == true){
                            y_gk-=1;
                        }
                        if (mouse_pos == 9 && x_gk<584 && same_direction == true){
                            x_gk+=7;
                            y_gk-=1;
                        }
                        if (mouse_pos == 10 && x_gk<=600 && same_direction == true){
                            x_gk+=12;
                            y_gk-=2;
                        }
                        if (mouse_pos == 14 && x_gk<=584 && same_direction == true){
                            x_gk+=9;
                        }
                        if (mouse_pos == 15 && x_gk<=600 && same_direction == true){
                            x_gk+=13;
                        }
                        if (same_direction == false){
                            if (goalkeeper_pos == 1){
                                x_gk-=13;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 2){
                                y_gk-=4;
                            }
                            if (goalkeeper_pos == 3){
                                x_gk+=14;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 4){
                                x_gk-=13;
                                y_gk-=1;
                            }
                            if (goalkeeper_pos == 5){
                                //nothing
                            }
                            if (goalkeeper_pos == 6){
                                x_gk+=14;
                                y_gk-=1;
                            }
                        }
                        if(sh%2==0){
                            x_ball+=fx/2;
                            y_ball-=fy/2;
                        }
                        else{
                            x_ball+=fx;
                            y_ball-=fy;
                        }
                        if(same_direction == true && y_ball-fy<=y && x_ball-fx<=x){
                            print"Result : Player 1 saved the goal";newline;newline;
                            PlaySound(NULL, 0, 0);
                            PlaySound(TEXT("no_goal.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                            SDL_Rect save_rect = { 0, 0, 800, 400};
                            if(choose_team == 1){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, bc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            else if(choose_team == 2){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            else if(choose_team == 3){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mu_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            else{
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, rm_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            sh=18;
                        }
                        else if(same_direction == false && y_ball-fy<=y && x_ball-fx<=x){
                            print"Result : Player 2 scored the goal";newline;newline;
                            results[5]=1;
                            number2++;
                            SDL_Rect score_rect = { 0, 0, 800, 400};
                            SDL_RenderCopy(renderer, score_show, NULL, &score_rect);
                            SDL_Delay(500);
                            SDL_RenderPresent(renderer);
                            SDL_Delay(2000);
                            sh=18;
                        }
                        if(sh>=9)
                            aa-=5*a;
                        else
                            aa-=a;
                        if(h%3==0)
                            a++;
                        sh++;
                        SDL_Rect image_back = { 0, 0, 800, 400 };
                        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                        SDL_RenderPresent(renderer);
                        if (choose_team == 1){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_bc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team == 2){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team == 3){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mu[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else{
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_rm[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
                        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
                        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
                        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
                        //std::cout<<number2;
                        if(choose_team == 1){
                            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        if(choose_team == 2){
                            SDL_Rect Man_City_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        if(choose_team == 3){
                            SDL_Rect Man_United_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        if(choose_team == 4){
                            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        if (choose_team_2 == 1){
                            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Rect Man_City_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Rect Man_United_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        else {
                            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        SDL_RenderPresent(renderer);
                        h++;
                        if(h==6)
                            h=1;
                        SDL_Delay(200);
                        if (sh==10){
                            SDL_Delay(200);
                            quit = true;
                        }
                    }
                }
                else if(x<x_ball){
                    fx=370-x;
                    fy=320-y;
                    bx=fx%10;
                    by=fy%10;
                    if(bx==1)
                        fx-=1;
                    else if(bx==2)
                        fx-=2;
                    else if(bx==3)
                        fx-=3;
                    else if(bx==4)
                        fx-=4;
                    else if(bx==5)
                        fx+=5;
                    else if(bx==6)
                        fx+=4;
                    else if(bx==7)
                        fx+=3;
                    else if(bx==8)
                        fx+=2;
                    else if(bx==9)
                        fx+=1;
                    if(by==1)
                        fy-=1;
                    else if(by==2)
                        fy-=2;
                    else if(by==3)
                        fy-=3;
                    else if(by==4)
                        fy-=4;
                    else if(by==5)
                        fy+=5;
                    else if(by==6)
                        fy+=4;
                    else if(by==7)
                        fy+=3;
                    else if(by==8)
                        fy+=2;
                    else if(by==9)
                        fy+=1;
                    fx=fx/10;
                    fy=fy/10;
                    while(sh<18){
                        if (mouse_pos == 1 && x_gk>120 && same_direction == true){
                            x_gk-=14;
                            y_gk-=3;
                        }
                        if (mouse_pos == 2 && y_gk>135 && same_direction == true){
                            x_gk-=5;
                            y_gk-=3;
                        }
                        if (mouse_pos == 6 && x_gk>120 && same_direction == true){
                            x_gk-=12;
                            y_gk-=2;
                        }
                        if (mouse_pos == 7 && x_gk>=236 && same_direction == true){
                            x_gk-=6;
                            y_gk-=1;
                        }
                        if (mouse_pos == 11 && x_gk>120 && same_direction == true){
                            x_gk-=13;
                        }
                        if (mouse_pos == 12 && x_gk>=236 && same_direction == true){
                            x_gk-=7;
                        }
                        if (same_direction == false){
                            if (goalkeeper_pos == 1){
                                x_gk-=13;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 2){
                                y_gk-=4;
                            }
                            if (goalkeeper_pos == 3){
                                x_gk+=14;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 4){
                                x_gk-=13;
                                y_gk-=1;
                            }
                            if (goalkeeper_pos == 5){
                                //nothing
                            }
                            if (goalkeeper_pos == 6){
                                x_gk+=14;
                                y_gk-=1;
                            }
                        }
                        if(sh%2==0){
                            x_ball-=fx/2;
                            y_ball-=fy/2;
                        }
                        else{
                            x_ball-=fx;
                            y_ball-=fy;
                        }
                        if(same_direction == true && y_ball-fy<=y && x_ball-fx<=x){
                            print"Result : Player 1 saved the goal";newline;newline;
                            PlaySound(NULL, 0, 0);
                            PlaySound(TEXT("no_goal.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                            SDL_Rect save_rect = { 0, 0, 800, 400};
                            if(choose_team == 1){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, bc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            else if(choose_team == 2){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            else if(choose_team == 3){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mu_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            else{
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, rm_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            sh=18;
                        }
                        else if(same_direction == false && y_ball-fy<=y && x_ball-fx<=x){
                            print"Result : Player 2 scored the goal";newline;newline;
                            results[5]=1;
                            number2++;
                            SDL_Rect score_rect = { 0, 0, 800, 400};
                            SDL_RenderCopy(renderer, score_show, NULL, &score_rect);
                            SDL_Delay(500);
                            SDL_RenderPresent(renderer);
                            SDL_Delay(3000);
                            sh=18;
                        }
                        if(sh>=9)
                            aa-=5*a;
                        else
                            aa-=a;
                        if(h%3==0)
                            a++;
                        sh++;
                        SDL_Rect image_back = { 0, 0, 800, 400 };
                        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                        SDL_RenderPresent(renderer);
                        if (choose_team == 1){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_bc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team == 2){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team == 3){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mu[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else{
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_rm[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
                        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
                        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
                        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
                        if(choose_team == 1){
                            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        if(choose_team == 2){
                            SDL_Rect Man_City_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        if(choose_team == 3){
                            SDL_Rect Man_United_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        if(choose_team == 4){
                            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        if (choose_team_2 == 1){
                            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Rect Man_City_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Rect Man_United_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        else {
                            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        SDL_RenderPresent(renderer);
                        h++;
                        if(h==6)
                            h=1;
                        SDL_Delay(200);
                        if (sh==10){
                            SDL_Delay(200);
                            quit=true;
                        }
                    }
                }
            }
        }
        SDL_RenderPresent(renderer);
        SDL_Rect image_back = { 0, 0, 800, 400 };
        SDL_Rect ball1 = { 370, 320, 75, 75};
        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
        SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
        if (choose_team == 1){
        SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_bc[1]);
        SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
        }
        else if (choose_team == 2){
            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mc[1]);
            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
        }
        else if (choose_team == 3){
            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mu[1]);
            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
        }
        else {
            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_rm[1]);
            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
        }
        if(choose_team == 1){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_bc[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
        }
        if(choose_team == 2){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mc[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Man_City_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
        }
        if(choose_team == 3){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mu[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Man_United_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
        }
        if(choose_team == 4){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_rm[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
        }
        if (choose_team_2 == 1){
            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
        }
        else if (choose_team_2 == 2){
            SDL_Rect Man_City_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
        }
        else if (choose_team_2 == 3){
            SDL_Rect Man_United_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
        }
        else {
            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
        }
        SDL_RenderPresent(renderer);
        if(voice==1){
            PlaySound(TEXT("cheering.wav"), NULL, SND_NOSTOP|SND_ASYNC);
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    x_ball=370,y_ball=320,fx=0,fy=0,sh=0,h=1,aa=75,a=0;
    x_gk=345,y_gk=200;
    bx=0,by=0;
    x=0,y=0;
    quit = false;
    goal_bool=false;
    first_click_player1=false;
    first_click_player2=false;
    std::cout << "            Turn 7  : Player 1 Is Shooter \n";
    print("Waiting for player 1 to shoot...");
    while (!quit){
        while(SDL_PollEvent(&e) != 0 ){
            if(e.type == SDL_QUIT){
                quit = true;
            }
            else if(e.type == SDL_MOUSEBUTTONDOWN){
                if (first_click_player1==false){
                    first_click_player1=true;
                    for(int i=0;i<32;i++) print"\b";
                    print("Waiting for player 2 to save... ");
                }
                SDL_Rect image_back = { 0, 0, 800, 400 };
                SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                SDL_RenderPresent(renderer);
                PlaySound(NULL, 0, 0);
                PlaySound(TEXT("quite.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                int x,y;
                SDL_GetMouseState( &x, &y );
                keydown = false;
                while (!keydown){
                        PlaySound(NULL, 0, 0);
                        PlaySound(TEXT("quite.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
                        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
                        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
                        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
                        if (choose_team_2 == 1){
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_bc[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mc[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mu[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        else {
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_rm[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        if(choose_team == 1){
                            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        if(choose_team == 2){
                            SDL_Rect Man_City_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        if(choose_team == 3){
                            SDL_Rect Man_United_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        if(choose_team == 4){
                            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        if (choose_team_2 == 1){
                            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Rect Man_City_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Rect Man_United_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        else {
                            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                        SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                        SDL_RenderPresent(renderer);
                    first_click_player2=false;
                    while (SDL_PollEvent(&saver)!=0){
                        SDL_WaitEvent(&saver);
                        if (saver.type == SDL_KEYDOWN){
                            if (saver.key.keysym.sym == SDLK_q){
                                keydown = true;
                                goalkeeper_pos = 1;
                            }
                            else if (saver.key.keysym.sym == SDLK_w){
                                keydown = true;
                                goalkeeper_pos = 2;
                            }
                            else if (saver.key.keysym.sym == SDLK_e){
                                keydown = true;
                                goalkeeper_pos = 3;
                            }
                            else if (saver.key.keysym.sym == SDLK_a){
                                keydown = true;
                                goalkeeper_pos = 4;
                            }
                            else if (saver.key.keysym.sym == SDLK_d){
                                keydown = true;
                                goalkeeper_pos = 6;
                            }
                        else{
                            keydown = true;
                            goalkeeper_pos = 5;
                        }
                            if (first_click_player2==false){
                                first_click_player2=true;
                                for(int i=0;i<32;i++) print"\b";
                                print"Both players had decided... Lets see what happen :)";
                                newline;
                            }
                        }
                    }
                }
                if (x<236 && x>=120 && y<190 && y>=135) mouse_pos = 1;
                else if (x<352 && x>=236 && y<190 && y>=135) mouse_pos = 2;
                else if (x<468 && x>=352 && y<190 && y>=135) mouse_pos = 3;
                else if (x<584 && x>=468 && y<190 && y>=135) mouse_pos = 4;
                else if (x<=700 && x>=584 && y<190 && y>=135) mouse_pos = 5;
                else if (x<236 && x>=120 && y<245 && y>=190) mouse_pos = 6;
                else if (x<352 && x>=236 && y<245 && y>=190) mouse_pos = 7;
                else if (x<468 && x>=352 && y<245 && y>=190) mouse_pos = 8;
                else if (x<584 && x>=468 && y<245 && y>=190) mouse_pos = 9;
                else if (x<=700 && x>=584 && y<245 && y>=190) mouse_pos = 10;
                else if (x<236 && x>=120 && y<=300 && y>=245) mouse_pos = 11;
                else if (x<352 && x>=236 && y<=300 && y>=245) mouse_pos = 12;
                else if (x<468 && x>=352 && y<=300 && y>=245) mouse_pos = 13;
                else if (x<584 && x>=468 && y<=300 && y>=245) mouse_pos = 14;
                else if (x<=700 && x>=584 && y<=300 && y>=245) mouse_pos = 15;
                if (mouse_pos == 1 || mouse_pos == 2) gk_num = 0;
                else if (mouse_pos == 3 || mouse_pos == 8 || mouse_pos == 13) gk_num = 1;
                else if (mouse_pos == 4 || mouse_pos == 5) gk_num = 2;
                else if (mouse_pos == 6) gk_num = 3;
                else if (mouse_pos == 7 || mouse_pos == 12) gk_num = 4;
                else if (mouse_pos == 9 || mouse_pos == 14) gk_num = 5;
                else if (mouse_pos == 10) gk_num = 6;
                else if (mouse_pos == 11) gk_num = 7;
                else if (mouse_pos == 15) gk_num = 8;
                if(gk_num==0){
                    x_chap=125;
                    y_chap=100;
                }
                else if(gk_num==1){
                    x_chap=100;
                    y_chap=125;
                }
                else if(gk_num==2){
                    x_chap=125;
                    y_chap=100;
                }
                else if(gk_num==3){
                    x_chap=150;
                    y_chap=100;
                }
                else if(gk_num==4){
                    x_chap=107;
                    y_chap=110;
                }
                else if(gk_num==5){
                    x_chap=107;
                    y_chap=110;
                }
                else if(gk_num==6){
                    x_chap=150;
                    y_chap=100;
                }
                else if(gk_num==7){
                    x_chap=150;
                    y_chap=100;
                }
                else if(gk_num==8){
                    x_chap=150;
                    y_chap=100;
                }
                same_direction = false;
                if (goalkeeper_pos == 1){
                    if (mouse_pos == 1 || mouse_pos == 2 || mouse_pos == 6 || mouse_pos == 7) same_direction = true;
                }
                else if (goalkeeper_pos == 2){
                    if (mouse_pos == 3 || mouse_pos == 8) same_direction = true;
                }
                else if (goalkeeper_pos == 3){
                    if (mouse_pos == 4 || mouse_pos == 5 || mouse_pos == 9 || mouse_pos == 10) same_direction = true;
                }
                else if (goalkeeper_pos == 4){
                    if (mouse_pos == 11 || mouse_pos == 12) same_direction = true;
                }
                else if (goalkeeper_pos == 5){
                    if (mouse_pos == 8 || mouse_pos == 13) same_direction = true;
                }
                else if (goalkeeper_pos == 6){
                    if (mouse_pos == 14 || mouse_pos == 15) same_direction = true;
                }
                if (same_direction != true){
                    if (goalkeeper_pos==1) gk_num = 0;
                    else if (goalkeeper_pos==2) gk_num = 1;
                    else if (goalkeeper_pos==3) gk_num = 2;
                    else if (goalkeeper_pos==4) gk_num = 3;
                    else if (goalkeeper_pos==5) gk_num = 1;
                    else if (goalkeeper_pos==6) gk_num = 6;
                }
                if(x>=x_ball){
                    fx=x-370;
                    fy=320-y;
                    bx=fx%10;
                    by=fy%10;
                    if(bx==1)
                        fx-=1;
                    else if(bx==2)
                        fx-=2;
                    else if(bx==3)
                        fx-=3;
                    else if(bx==4)
                        fx-=4;
                    else if(bx==5)
                        fx+=5;
                    else if(bx==6)
                        fx+=4;
                    else if(bx==7)
                        fx+=3;
                    else if(bx==8)
                        fx+=2;
                    else if(bx==9)
                        fx+=1;
                    if(by==1)
                        fy-=1;
                    else if(by==2)
                        fy-=2;
                    else if(by==3)
                        fy-=3;
                    else if(by==4)
                        fy-=4;
                    else if(by==5)
                        fy+=5;
                    else if(by==6)
                        fy+=4;
                    else if(by==7)
                        fy+=3;
                    else if(by==8)
                        fy+=2;
                    else if(by==9)
                        fy+=1;
                    fx=fx/10;
                    fy=fy/10;
                    while(sh<18){
                        if (mouse_pos == 3 && y_gk>135 && same_direction == true){
                            y_gk-=4;
                        }
                        if (mouse_pos == 4 && y_gk>135 && same_direction == true){
                            x_gk+=8;
                            y_gk-=3;
                        }
                        if (mouse_pos == 5 && y_gk>135 && same_direction == true){
                            x_gk+=14;
                            y_gk-=3;
                        }
                        if (mouse_pos == 8 && same_direction == true){
                            y_gk-=1;
                        }
                        if (mouse_pos == 9 && x_gk<584 && same_direction == true){
                            x_gk+=7;
                            y_gk-=1;
                        }
                        if (mouse_pos == 10 && x_gk<=600 && same_direction == true){
                            x_gk+=12;
                            y_gk-=2;
                        }
                        if (mouse_pos == 14 && x_gk<=584 && same_direction == true){
                            x_gk+=9;
                        }
                        if (mouse_pos == 15 && x_gk<=600 && same_direction == true){
                            x_gk+=13;
                        }
                        if (same_direction == false){
                            if (goalkeeper_pos == 1){
                                x_gk-=13;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 2){
                                y_gk-=4;
                            }
                            if (goalkeeper_pos == 3){
                                x_gk+=14;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 4){
                                x_gk-=13;
                                y_gk-=1;
                            }
                            if (goalkeeper_pos == 5){
                                //nothing
                            }
                            if (goalkeeper_pos == 6){
                                x_gk+=14;
                                y_gk-=1;
                            }
                        }
                        if (x_gk+30<468 && x_gk+30>=352 && y_gk+10<190 && y_gk+10>=135 && gk_num == 1) gk_pos = 3; // 60 35
                        else if (x_gk+100<584 && x_gk+100>=468 && y_gk+10<190 && y_gk+10>=135 && gk_num == 2) gk_pos = 4; // 170 45
                        else if (x_gk+100<=700 && x_gk+100>=584 && y_gk+10<190 && y_gk+10>=135 && gk_num == 2) gk_pos = 5; // 170 45
                        else if (x_gk+30<468 && x_gk+30>=352 && y_gk+10<245 && y_gk+10>=190 && gk_num == 1) gk_pos = 8; // 60 35
                        else if (x_gk+180<584 && x_gk+180>=468 && y_gk+40<245 && y_gk+40>=190 && gk_num == 5) gk_pos = 9; // 180 80
                        else if (x_gk+170<=700 && x_gk+170>=584 && y_gk+50<245 && y_gk+50>=190 && gk_num == 6) gk_pos = 10; // 210 100
                        else if (x_gk+30<468 && x_gk+30>=352 && y_gk+100<=300 && y_gk+100>=245 && gk_num == 1) gk_pos = 13; // 60 35
                        else if (x_gk+10<584 && x_gk+10>=468 && y_gk+50<=300 && y_gk+50>=245 && gk_num == 5) gk_pos = 14; // 180 80
                        else if (x_gk+200<=700 && x_gk+200>=584 && y_gk+100<=300 && y_gk+100>=245 && gk_num == 8) gk_pos = 15; // 270 140
                        if(sh%2==0){
                            x_ball+=fx/2;
                            y_ball-=fy/2;
                        }
                        else{
                            x_ball+=fx;
                            y_ball-=fy;
                        }
                        if (gk_pos == 9 && mouse_pos == 14) gk_pos=mouse_pos;
                        if (gk_pos == 8 && mouse_pos == 13) gk_pos=mouse_pos;
                        //std::cout<<gk_pos<<"\t"<<mouse_pos<<"\n";
                        if(y_ball-fy<=y && gk_pos==mouse_pos && x_ball-fx<=x && goal_bool==false){
                            print"Result : Player 2 saved the goal";newline;newline;
                            PlaySound(NULL, 0, 0);
                            PlaySound(TEXT("no_goal.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                            SDL_Rect save_rect = { 0, 0, 800, 400};
                            if(choose_team_2 == 1){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, bc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            else if(choose_team_2 == 2){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            else if(choose_team_2 == 3){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mu_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            else{
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, rm_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            sh=18;
                        }
                        else if(same_direction == false && y_ball-fy<=y && x_ball-fx<=x){
                            print"Result : Player 1 scored the goal";newline;newline;
                            results[6]=1;
                            number++;
                            SDL_Rect score_rect = { 0, 0, 800, 400};
                            SDL_RenderCopy(renderer, score_show, NULL, &score_rect);
                            SDL_Delay(500);
                            SDL_RenderPresent(renderer);
                            SDL_Delay(2000);
                            sh=18;
                        }
                        if(sh>=9)
                            aa-=5*a;
                        else
                            aa-=a;
                        if(h%3==0)
                            a++;
                        sh++;
                        SDL_Rect image_back = { 0, 0, 800, 400 };
                        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                        SDL_RenderPresent(renderer);
                        if (choose_team_2 == 1){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_bc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team_2 == 2){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team_2 == 3){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mu[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else{
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_rm[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
                        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
                        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
                        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
                        if(choose_team == 1){
                            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        if(choose_team == 2){
                            SDL_Rect Man_City_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        if(choose_team == 3){
                            SDL_Rect Man_United_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        if(choose_team == 4){
                            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        if (choose_team_2 == 1){
                            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Rect Man_City_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Rect Man_United_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        else {
                            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        SDL_RenderPresent(renderer);
                        h++;
                        if(h==6)
                            h=1;
                        SDL_Delay(200);
                        if (sh==10){
                            SDL_Delay(200);
                            quit=true;
                        }
                    }
                }
                else if(x<x_ball){
                    fx=370-x;
                    fy=320-y;
                    bx=fx%10;
                    by=fy%10;
                    if(bx==1)
                        fx-=1;
                    else if(bx==2)
                        fx-=2;
                    else if(bx==3)
                        fx-=3;
                    else if(bx==4)
                        fx-=4;
                    else if(bx==5)
                        fx+=5;
                    else if(bx==6)
                        fx+=4;
                    else if(bx==7)
                        fx+=3;
                    else if(bx==8)
                        fx+=2;
                    else if(bx==9)
                        fx+=1;
                    if(by==1)
                        fy-=1;
                    else if(by==2)
                        fy-=2;
                    else if(by==3)
                        fy-=3;
                    else if(by==4)
                        fy-=4;
                    else if(by==5)
                        fy+=5;
                    else if(by==6)
                        fy+=4;
                    else if(by==7)
                        fy+=3;
                    else if(by==8)
                        fy+=2;
                    else if(by==9)
                        fy+=1;
                    fx=fx/10;
                    fy=fy/10;
                    while(sh<18){
                        if (mouse_pos == 1 && x_gk>120 && same_direction == true){
                            x_gk-=14;
                            y_gk-=3;
                        }
                        if (mouse_pos == 2 && y_gk>135 && same_direction == true){
                            x_gk-=5;
                            y_gk-=3;
                        }
                        if (mouse_pos == 6 && x_gk>110 && same_direction == true){
                            x_gk-=12;
                            y_gk-=2;
                        }
                        if (mouse_pos == 7 && x_gk>=236 && same_direction == true){
                            x_gk-=6;
                            y_gk-=1;
                        }
                        if (mouse_pos == 11 && x_gk>120 && same_direction == true){
                            x_gk-=13;
                        }
                        if (mouse_pos == 12 && x_gk>=236 && same_direction == true){
                            x_gk-=7;
                        }
                        if (same_direction == false){
                            if (goalkeeper_pos == 1){
                                x_gk-=13;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 2){
                                y_gk-=4;
                            }
                            if (goalkeeper_pos == 3){
                                x_gk+=14;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 4){
                                x_gk-=13;
                                y_gk-=1;
                            }
                            if (goalkeeper_pos == 5){
                                //nothing
                            }
                            if (goalkeeper_pos == 6){
                                x_gk+=14;
                                y_gk-=1;
                            }
                        }
                        if (x_gk+15<236 && x_gk+15>=120 && y_gk+25<190 && y_gk+25>=135 && gk_num == 0) gk_pos = 1;
                        else if (x_gk+15<352 && x_gk+15>=236 && y_gk+15<190 && y_gk+15>=135 && gk_num == 0) gk_pos = 2;
                        else if (x_gk<236 && x_gk>=120 && y_gk+50<245 && y_gk+50>=190 && gk_num == 3) gk_pos = 6; // 15 100
                        else if (x_gk+10<352 && x_gk+10>=236 && y_gk+50<245 && y_gk+50>=190 && gk_num == 4) gk_pos = 7; // 20 80
                        else if (x_gk<236 && x_gk>=120 && y_gk+70<=300 && y_gk+70>=245 && gk_num == 7) gk_pos = 11; // 35 140
                        else if (x_gk+10<352 && x_gk+10>=236 && y_gk+50<=300 && y_gk+50>=245 && gk_num == 4) gk_pos = 12; // 20 80
                        else if (x_gk+30<468 && x_gk+30>=352 && y_gk+200<=300 && y_gk+200>=245 && gk_num == 1) gk_pos = 13; // 60 35
                        if(sh%2==0){
                            x_ball-=fx/2;
                            y_ball-=fy/2;
                        }
                        else{
                            x_ball-=fx;
                            y_ball-=fy;
                        }
                        //std::cout<<gk_pos<<"\t"<<mouse_pos<<"\n";
                        if (gk_pos == 8 && mouse_pos == 13) gk_pos=mouse_pos;
                        if(y_ball-fy<=y && gk_pos==mouse_pos && x_ball-fx<=x && goal_bool==false){
                            print"Result : Player 2 saved the goal";newline;newline;
                            PlaySound(NULL, 0, 0);
                            SDL_Delay(200);
                            PlaySound(TEXT("no_goal.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                            SDL_Rect save_rect = { 0, 0, 800, 400};
                            if(choose_team_2 == 1){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, bc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            else if(choose_team_2 == 2){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            else if(choose_team_2 == 3){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mu_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            else{
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, rm_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            sh=18;
                        }
                        else if(same_direction == false && y_ball-fy<=y && x_ball-fx<=x){
                            print"Result : Player 1 scored the goal";newline;newline;
                            results[6]=1;
                            number++;
                            SDL_Rect score_rect = { 0, 0, 800, 400};
                            SDL_RenderCopy(renderer, score_show, NULL, &score_rect);
                            SDL_Delay(500);
                            SDL_RenderPresent(renderer);
                            SDL_Delay(2000);
                            sh=18;
                        }
                        //std::cout<<number;
                        if(sh>=9)
                            aa-=5*a;
                        else
                            aa-=a;
                        if(h%3==0)
                            a++;
                        sh++;
                        SDL_Rect image_back = { 0, 0, 800, 400 };
                        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                        SDL_RenderPresent(renderer);
                        if (choose_team_2 == 1){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_bc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team_2 == 2){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team_2 == 3){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mu[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else{
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_rm[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
                        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
                        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
                        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
                        if(choose_team == 1){
                            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        if(choose_team == 2){
                            SDL_Rect Man_City_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        if(choose_team == 3){
                            SDL_Rect Man_United_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        if(choose_team == 4){
                            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        if (choose_team_2 == 1){
                            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Rect Man_City_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Rect Man_United_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        else {
                            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        SDL_RenderPresent(renderer);
                        h++;
                        if(h==6)
                            h=1;
                        SDL_Delay(200);
                        if (sh==10){
                            SDL_Delay(200);
                            quit=true;
                        }
                    }
                }
            }
        }
        //SDL_RenderPresent(renderer);
        SDL_Rect image_back = { 0, 0, 800, 400 };
        SDL_Rect ball1 = { 370, 320, 75, 75};
        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
        SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
        if(choose_team == 1){
            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
        }
        if(choose_team == 2){
            SDL_Rect Man_City_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
        }
        if(choose_team == 3){
            SDL_Rect Man_United_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
        }
        if(choose_team == 4){
            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
        }
        if (choose_team_2 == 1){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_bc[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
        }
        else if (choose_team_2 == 2){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mc[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Man_City_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
        }
        else if (choose_team_2 == 3){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mu[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Man_United_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
        }
        else {
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_rm[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
        }
        SDL_RenderPresent(renderer);
        if(voice==1){
            PlaySound(TEXT("cheering.wav"), NULL, SND_NOSTOP|SND_ASYNC);
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    x_ball=370,y_ball=320,fx=0,fy=0,sh=0,h=1,aa=75,a=0;
    x_gk=345,y_gk=200;
    bx=0,by=0;
    x=0,y=0;
    quit = false;
    goal_bool=false;
    first_click_player1=false;
    first_click_player2=false;
    std::cout << "            Turn 8  : Player 2 Is Shooter \n";
    print("Waiting for player 2 to shoot...");
    while (!quit){
        while(SDL_PollEvent(&e) != 0 ){
            if(e.type == SDL_QUIT){
                quit = true;
            }
            else if(e.type == SDL_MOUSEBUTTONDOWN){
                if (first_click_player1==false){
                    first_click_player1=true;
                    for(int i=0;i<32;i++) print"\b";
                    print("Waiting for player 1 to save... ");
                }
                SDL_Rect image_back = { 0, 0, 800, 400 };
                SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                SDL_RenderPresent(renderer);
                int x,y;
                SDL_GetMouseState( &x, &y );
                keydown = false;
                while (!keydown){
                        PlaySound(NULL, 0, 0);
                        PlaySound(TEXT("quite.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
                        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
                        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
                        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
                        if (choose_team == 1){
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_bc[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        else if (choose_team == 2){
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mc[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        else if (choose_team == 3){
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mu[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        else {
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_rm[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        if(choose_team == 1){
                            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        if(choose_team == 2){
                            SDL_Rect Man_City_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        if(choose_team == 3){
                            SDL_Rect Man_United_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        if(choose_team == 4){
                            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        if (choose_team_2 == 1){
                            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Rect Man_City_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Rect Man_United_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        else {
                            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                        SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                        SDL_RenderPresent(renderer);
                    while (SDL_PollEvent(&saver)!=0){
                        SDL_WaitEvent(&saver);
                        if (saver.type == SDL_KEYDOWN){
                            if (saver.key.keysym.sym == SDLK_q){
                                keydown = true;
                                goalkeeper_pos = 1;
                            }
                            else if (saver.key.keysym.sym == SDLK_w){
                                keydown = true;
                                goalkeeper_pos = 2;
                            }
                            else if (saver.key.keysym.sym == SDLK_e){
                                keydown = true;
                                goalkeeper_pos = 3;
                            }
                            else if (saver.key.keysym.sym == SDLK_a){
                                keydown = true;
                                goalkeeper_pos = 4;
                            }
                            else if (saver.key.keysym.sym == SDLK_d){
                                keydown = true;
                                goalkeeper_pos = 6;
                            }
                        else{
                            keydown = true;
                            goalkeeper_pos = 5;
                        }
                        if (first_click_player2==false){
                                first_click_player2=true;
                                for(int i=0;i<32;i++) print"\b";
                                print"Both players had decided... Lets see what happen :)";
                                newline;
                            }
                        }
                    }
                }
                if (x<236 && x>=120 && y<190 && y>=135) mouse_pos = 1;
                else if (x<352 && x>=236 && y<190 && y>=135) mouse_pos = 2;
                else if (x<468 && x>=352 && y<190 && y>=135) mouse_pos = 3;
                else if (x<584 && x>=468 && y<190 && y>=135) mouse_pos = 4;
                else if (x<=700 && x>=584 && y<190 && y>=135) mouse_pos = 5;
                else if (x<236 && x>=120 && y<245 && y>=190) mouse_pos = 6;
                else if (x<352 && x>=236 && y<245 && y>=190) mouse_pos = 7;
                else if (x<468 && x>=352 && y<245 && y>=190) mouse_pos = 8;
                else if (x<584 && x>=468 && y<245 && y>=190) mouse_pos = 9;
                else if (x<=700 && x>=584 && y<245 && y>=190) mouse_pos = 10;
                else if (x<236 && x>=120 && y<=300 && y>=245) mouse_pos = 11;
                else if (x<352 && x>=236 && y<=300 && y>=245) mouse_pos = 12;
                else if (x<468 && x>=352 && y<=300 && y>=245) mouse_pos = 13;
                else if (x<584 && x>=468 && y<=300 && y>=245) mouse_pos = 14;
                else if (x<=700 && x>=584 && y<=300 && y>=245) mouse_pos = 15;
                // 1 6 11 // 2 7 12 // 3 8 13 // 4 9 14 // 5 10 15
                if (mouse_pos == 1 || mouse_pos == 2) gk_num = 0;
                else if (mouse_pos == 3 || mouse_pos == 8 || mouse_pos == 13) gk_num = 1;
                else if (mouse_pos == 4 || mouse_pos == 5) gk_num = 2;
                else if (mouse_pos == 6) gk_num = 3;
                else if (mouse_pos == 7 || mouse_pos == 12) gk_num = 4;
                else if (mouse_pos == 9 || mouse_pos == 14) gk_num = 5;
                else if (mouse_pos == 10) gk_num = 6;
                else if (mouse_pos == 11) gk_num = 7;
                else if (mouse_pos == 15) gk_num = 8;
                if(gk_num==0){
                    x_chap=125;
                    y_chap=100;
                }
                else if(gk_num==1){
                    x_chap=100;
                    y_chap=125;
                }
                else if(gk_num==2){
                    x_chap=125;
                    y_chap=100;
                }
                else if(gk_num==3){
                    x_chap=150;
                    y_chap=100;
                }
                else if(gk_num==4){
                    x_chap=107;
                    y_chap=110;
                }
                else if(gk_num==5){
                    x_chap=107;
                    y_chap=110;
                }
                else if(gk_num==6){
                    x_chap=150;
                    y_chap=100;
                }
                else if(gk_num==7){
                    x_chap=150;
                    y_chap=100;
                }
                else if(gk_num==8){
                    x_chap=150;
                    y_chap=100;
                }
                same_direction = false;
                if (goalkeeper_pos == 1){
                    if (mouse_pos == 1 || mouse_pos == 2 || mouse_pos == 6 || mouse_pos == 7) same_direction = true;
                }
                else if (goalkeeper_pos == 2){
                    if (mouse_pos == 3 || mouse_pos == 8) same_direction = true;
                }
                else if (goalkeeper_pos == 3){
                    if (mouse_pos == 4 || mouse_pos == 5 || mouse_pos == 9 || mouse_pos == 10) same_direction = true;
                }
                else if (goalkeeper_pos == 4){
                    if (mouse_pos == 11 || mouse_pos == 12) same_direction = true;
                }
                else if (goalkeeper_pos == 5){
                    if (mouse_pos == 8 || mouse_pos == 13) same_direction = true;
                }
                else if (goalkeeper_pos == 6){
                    if (mouse_pos == 14 || mouse_pos == 15) same_direction = true;
                }
                if (same_direction != true){
                    if (goalkeeper_pos==1) gk_num = 0;
                    else if (goalkeeper_pos==2) gk_num = 1;
                    else if (goalkeeper_pos==3) gk_num = 2;
                    else if (goalkeeper_pos==4) gk_num = 3;
                    else if (goalkeeper_pos==5) gk_num = 1;
                    else if (goalkeeper_pos==6) gk_num = 6;
                }
                if(x>=x_ball){
                    fx=x-370;
                    fy=320-y;
                    bx=fx%10;
                    by=fy%10;
                    if(bx==1)
                        fx-=1;
                    else if(bx==2)
                        fx-=2;
                    else if(bx==3)
                        fx-=3;
                    else if(bx==4)
                        fx-=4;
                    else if(bx==5)
                        fx+=5;
                    else if(bx==6)
                        fx+=4;
                    else if(bx==7)
                        fx+=3;
                    else if(bx==8)
                        fx+=2;
                    else if(bx==9)
                        fx+=1;
                    if(by==1)
                        fy-=1;
                    else if(by==2)
                        fy-=2;
                    else if(by==3)
                        fy-=3;
                    else if(by==4)
                        fy-=4;
                    else if(by==5)
                        fy+=5;
                    else if(by==6)
                        fy+=4;
                    else if(by==7)
                        fy+=3;
                    else if(by==8)
                        fy+=2;
                    else if(by==9)
                        fy+=1;
                    fx=fx/10;
                    fy=fy/10;
                    while(sh<18){
                        if (mouse_pos == 3 && y_gk>135 && same_direction == true){
                            y_gk-=4;
                        }
                        if (mouse_pos == 4 && y_gk>135 && same_direction == true){
                            x_gk+=8;
                            y_gk-=3;
                        }
                        if (mouse_pos == 5 && y_gk>135 && same_direction == true){
                            x_gk+=14;
                            y_gk-=3;
                        }
                        if (mouse_pos == 8 && same_direction == true){
                            y_gk-=1;
                        }
                        if (mouse_pos == 9 && x_gk<584 && same_direction == true){
                            x_gk+=7;
                            y_gk-=1;
                        }
                        if (mouse_pos == 10 && x_gk<=600 && same_direction == true){
                            x_gk+=12;
                            y_gk-=2;
                        }
                        if (mouse_pos == 14 && x_gk<=584 && same_direction == true){
                            x_gk+=9;
                        }
                        if (mouse_pos == 15 && x_gk<=600 && same_direction == true){
                            x_gk+=13;
                        }
                        if (same_direction == false){
                            if (goalkeeper_pos == 1){
                                x_gk-=13;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 2){
                                y_gk-=4;
                            }
                            if (goalkeeper_pos == 3){
                                x_gk+=14;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 4){
                                x_gk-=13;
                                y_gk-=1;
                            }
                            if (goalkeeper_pos == 5){
                                //nothing
                            }
                            if (goalkeeper_pos == 6){
                                x_gk+=14;
                                y_gk-=1;
                            }
                        }
                        if(sh%2==0){
                            x_ball+=fx/2;
                            y_ball-=fy/2;
                        }
                        else{
                            x_ball+=fx;
                            y_ball-=fy;
                        }
                        if(same_direction == true && y_ball-fy<=y && x_ball-fx<=x){
                            print"Result : Player 1 saved the goal";newline;newline;
                            PlaySound(NULL, 0, 0);
                            PlaySound(TEXT("no_goal.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                            SDL_Rect save_rect = { 0, 0, 800, 400};
                            if(choose_team == 1){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, bc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            else if(choose_team == 2){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            else if(choose_team == 3){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mu_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            else{
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, rm_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            sh=18;
                        }
                        else if(same_direction == false && y_ball-fy<=y && x_ball-fx<=x){
                            print"Result : Player 2 scored the goal";newline;newline;
                            results[7]=1;
                            number2++;
                            SDL_Rect score_rect = { 0, 0, 800, 400};
                            SDL_RenderCopy(renderer, score_show, NULL, &score_rect);
                            SDL_Delay(500);
                            SDL_RenderPresent(renderer);
                            SDL_Delay(2000);
                            sh=18;
                        }
                        if(sh>=9)
                            aa-=5*a;
                        else
                            aa-=a;
                        if(h%3==0)
                            a++;
                        sh++;
                        SDL_Rect image_back = { 0, 0, 800, 400 };
                        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                        SDL_RenderPresent(renderer);
                        if (choose_team == 1){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_bc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team == 2){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team == 3){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mu[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else{
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_rm[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
                        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
                        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
                        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
                        //std::cout<<number2;
                        if(choose_team == 1){
                            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        if(choose_team == 2){
                            SDL_Rect Man_City_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        if(choose_team == 3){
                            SDL_Rect Man_United_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        if(choose_team == 4){
                            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        if (choose_team_2 == 1){
                            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Rect Man_City_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Rect Man_United_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        else {
                            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        SDL_RenderPresent(renderer);
                        h++;
                        if(h==6)
                            h=1;
                        SDL_Delay(200);
                        if (sh==10){
                            SDL_Delay(200);
                            quit = true;
                        }
                    }
                }
                else if(x<x_ball){
                    fx=370-x;
                    fy=320-y;
                    bx=fx%10;
                    by=fy%10;
                    if(bx==1)
                        fx-=1;
                    else if(bx==2)
                        fx-=2;
                    else if(bx==3)
                        fx-=3;
                    else if(bx==4)
                        fx-=4;
                    else if(bx==5)
                        fx+=5;
                    else if(bx==6)
                        fx+=4;
                    else if(bx==7)
                        fx+=3;
                    else if(bx==8)
                        fx+=2;
                    else if(bx==9)
                        fx+=1;
                    if(by==1)
                        fy-=1;
                    else if(by==2)
                        fy-=2;
                    else if(by==3)
                        fy-=3;
                    else if(by==4)
                        fy-=4;
                    else if(by==5)
                        fy+=5;
                    else if(by==6)
                        fy+=4;
                    else if(by==7)
                        fy+=3;
                    else if(by==8)
                        fy+=2;
                    else if(by==9)
                        fy+=1;
                    fx=fx/10;
                    fy=fy/10;
                    while(sh<18){
                        if (mouse_pos == 1 && x_gk>120 && same_direction == true){
                            x_gk-=14;
                            y_gk-=3;
                        }
                        if (mouse_pos == 2 && y_gk>135 && same_direction == true){
                            x_gk-=5;
                            y_gk-=3;
                        }
                        if (mouse_pos == 6 && x_gk>120 && same_direction == true){
                            x_gk-=12;
                            y_gk-=2;
                        }
                        if (mouse_pos == 7 && x_gk>=236 && same_direction == true){
                            x_gk-=6;
                            y_gk-=1;
                        }
                        if (mouse_pos == 11 && x_gk>120 && same_direction == true){
                            x_gk-=13;
                        }
                        if (mouse_pos == 12 && x_gk>=236 && same_direction == true){
                            x_gk-=7;
                        }
                        if (same_direction == false){
                            if (goalkeeper_pos == 1){
                                x_gk-=13;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 2){
                                y_gk-=4;
                            }
                            if (goalkeeper_pos == 3){
                                x_gk+=14;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 4){
                                x_gk-=13;
                                y_gk-=1;
                            }
                            if (goalkeeper_pos == 5){
                                //nothing
                            }
                            if (goalkeeper_pos == 6){
                                x_gk+=14;
                                y_gk-=1;
                            }
                        }
                        if(sh%2==0){
                            x_ball-=fx/2;
                            y_ball-=fy/2;
                        }
                        else{
                            x_ball-=fx;
                            y_ball-=fy;
                        }
                        if(same_direction == true && y_ball-fy<=y && x_ball-fx<=x){
                            print"Result : Player 1 saved the goal";newline;newline;
                            PlaySound(NULL, 0, 0);
                            PlaySound(TEXT("no_goal.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                            SDL_Rect save_rect = { 0, 0, 800, 400};
                            if(choose_team == 1){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, bc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            else if(choose_team == 2){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            else if(choose_team == 3){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mu_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            else{
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, rm_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            sh=18;
                        }
                        else if(same_direction == false && y_ball-fy<=y && x_ball-fx<=x){
                            print"Result : Player 2 scored the goal";newline;newline;
                            results[7]=1;
                            number2++;
                            SDL_Rect score_rect = { 0, 0, 800, 400};
                            SDL_RenderCopy(renderer, score_show, NULL, &score_rect);
                            SDL_Delay(500);
                            SDL_RenderPresent(renderer);
                            SDL_Delay(3000);
                            sh=18;
                        }
                        if(sh>=9)
                            aa-=5*a;
                        else
                            aa-=a;
                        if(h%3==0)
                            a++;
                        sh++;
                        SDL_Rect image_back = { 0, 0, 800, 400 };
                        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                        SDL_RenderPresent(renderer);
                        if (choose_team == 1){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_bc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team == 2){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team == 3){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mu[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else{
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_rm[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
                        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
                        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
                        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
                        if(choose_team == 1){
                            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        if(choose_team == 2){
                            SDL_Rect Man_City_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        if(choose_team == 3){
                            SDL_Rect Man_United_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        if(choose_team == 4){
                            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        if (choose_team_2 == 1){
                            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Rect Man_City_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Rect Man_United_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        else {
                            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        SDL_RenderPresent(renderer);
                        h++;
                        if(h==6)
                            h=1;
                        SDL_Delay(200);
                        if (sh==10){
                            SDL_Delay(200);
                            quit=true;
                        }
                    }
                }
            }
        }
        SDL_RenderPresent(renderer);
        SDL_Rect image_back = { 0, 0, 800, 400 };
        SDL_Rect ball1 = { 370, 320, 75, 75};
        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
        SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
        if (choose_team == 1){
        SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_bc[1]);
        SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
        }
        else if (choose_team == 2){
            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mc[1]);
            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
        }
        else if (choose_team == 3){
            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mu[1]);
            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
        }
        else {
            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_rm[1]);
            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
        }
        if(choose_team == 1){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_bc[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
        }
        if(choose_team == 2){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mc[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Man_City_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
        }
        if(choose_team == 3){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mu[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Man_United_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
        }
        if(choose_team == 4){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_rm[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
        }
        if (choose_team_2 == 1){
            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
        }
        else if (choose_team_2 == 2){
            SDL_Rect Man_City_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
        }
        else if (choose_team_2 == 3){
            SDL_Rect Man_United_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
        }
        else {
            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
        }
        SDL_RenderPresent(renderer);
        if(voice==1){
            PlaySound(TEXT("cheering.wav"), NULL, SND_NOSTOP|SND_ASYNC);
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    x_ball=370,y_ball=320,fx=0,fy=0,sh=0,h=1,aa=75,a=0;
    x_gk=345,y_gk=200;
    bx=0,by=0;
    x=0,y=0;
    quit = false;
    goal_bool=false;
    first_click_player1=false;
    first_click_player2=false;
    std::cout << "            Turn 9  : Player 1 Is Shooter \n";
    print("Waiting for player 1 to shoot...");
    while (!quit){
        while(SDL_PollEvent(&e) != 0 ){
            if(e.type == SDL_QUIT){
                quit = true;
            }
            else if(e.type == SDL_MOUSEBUTTONDOWN){
                if (first_click_player1==false){
                    first_click_player1=true;
                    for(int i=0;i<32;i++) print"\b";
                    print("Waiting for player 2 to save... ");
                }
                SDL_Rect image_back = { 0, 0, 800, 400 };
                SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                SDL_RenderPresent(renderer);
                PlaySound(NULL, 0, 0);
                PlaySound(TEXT("quite.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                int x,y;
                SDL_GetMouseState( &x, &y );
                keydown = false;
                while (!keydown){
                        PlaySound(NULL, 0, 0);
                        PlaySound(TEXT("quite.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
                        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
                        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
                        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
                        if (choose_team_2 == 1){
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_bc[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mc[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mu[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        else {
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_rm[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        if(choose_team == 1){
                            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        if(choose_team == 2){
                            SDL_Rect Man_City_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        if(choose_team == 3){
                            SDL_Rect Man_United_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        if(choose_team == 4){
                            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        if (choose_team_2 == 1){
                            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Rect Man_City_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Rect Man_United_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        else {
                            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                        SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                        SDL_RenderPresent(renderer);
                    first_click_player2=false;
                    while (SDL_PollEvent(&saver)!=0){
                        SDL_WaitEvent(&saver);
                        if (saver.type == SDL_KEYDOWN){
                            if (saver.key.keysym.sym == SDLK_q){
                                keydown = true;
                                goalkeeper_pos = 1;
                            }
                            else if (saver.key.keysym.sym == SDLK_w){
                                keydown = true;
                                goalkeeper_pos = 2;
                            }
                            else if (saver.key.keysym.sym == SDLK_e){
                                keydown = true;
                                goalkeeper_pos = 3;
                            }
                            else if (saver.key.keysym.sym == SDLK_a){
                                keydown = true;
                                goalkeeper_pos = 4;
                            }
                            else if (saver.key.keysym.sym == SDLK_d){
                                keydown = true;
                                goalkeeper_pos = 6;
                            }
                        else{
                            keydown = true;
                            goalkeeper_pos = 5;
                        }
                            if (first_click_player2==false){
                                first_click_player2=true;
                                for(int i=0;i<32;i++) print"\b";
                                print"Both players had decided... Lets see what happen :)";
                                newline;
                            }
                        }
                    }
                }
                if (x<236 && x>=120 && y<190 && y>=135) mouse_pos = 1;
                else if (x<352 && x>=236 && y<190 && y>=135) mouse_pos = 2;
                else if (x<468 && x>=352 && y<190 && y>=135) mouse_pos = 3;
                else if (x<584 && x>=468 && y<190 && y>=135) mouse_pos = 4;
                else if (x<=700 && x>=584 && y<190 && y>=135) mouse_pos = 5;
                else if (x<236 && x>=120 && y<245 && y>=190) mouse_pos = 6;
                else if (x<352 && x>=236 && y<245 && y>=190) mouse_pos = 7;
                else if (x<468 && x>=352 && y<245 && y>=190) mouse_pos = 8;
                else if (x<584 && x>=468 && y<245 && y>=190) mouse_pos = 9;
                else if (x<=700 && x>=584 && y<245 && y>=190) mouse_pos = 10;
                else if (x<236 && x>=120 && y<=300 && y>=245) mouse_pos = 11;
                else if (x<352 && x>=236 && y<=300 && y>=245) mouse_pos = 12;
                else if (x<468 && x>=352 && y<=300 && y>=245) mouse_pos = 13;
                else if (x<584 && x>=468 && y<=300 && y>=245) mouse_pos = 14;
                else if (x<=700 && x>=584 && y<=300 && y>=245) mouse_pos = 15;
                if (mouse_pos == 1 || mouse_pos == 2) gk_num = 0;
                else if (mouse_pos == 3 || mouse_pos == 8 || mouse_pos == 13) gk_num = 1;
                else if (mouse_pos == 4 || mouse_pos == 5) gk_num = 2;
                else if (mouse_pos == 6) gk_num = 3;
                else if (mouse_pos == 7 || mouse_pos == 12) gk_num = 4;
                else if (mouse_pos == 9 || mouse_pos == 14) gk_num = 5;
                else if (mouse_pos == 10) gk_num = 6;
                else if (mouse_pos == 11) gk_num = 7;
                else if (mouse_pos == 15) gk_num = 8;
                if(gk_num==0){
                    x_chap=125;
                    y_chap=100;
                }
                else if(gk_num==1){
                    x_chap=100;
                    y_chap=125;
                }
                else if(gk_num==2){
                    x_chap=125;
                    y_chap=100;
                }
                else if(gk_num==3){
                    x_chap=150;
                    y_chap=100;
                }
                else if(gk_num==4){
                    x_chap=107;
                    y_chap=110;
                }
                else if(gk_num==5){
                    x_chap=107;
                    y_chap=110;
                }
                else if(gk_num==6){
                    x_chap=150;
                    y_chap=100;
                }
                else if(gk_num==7){
                    x_chap=150;
                    y_chap=100;
                }
                else if(gk_num==8){
                    x_chap=150;
                    y_chap=100;
                }
                same_direction = false;
                if (goalkeeper_pos == 1){
                    if (mouse_pos == 1 || mouse_pos == 2 || mouse_pos == 6 || mouse_pos == 7) same_direction = true;
                }
                else if (goalkeeper_pos == 2){
                    if (mouse_pos == 3 || mouse_pos == 8) same_direction = true;
                }
                else if (goalkeeper_pos == 3){
                    if (mouse_pos == 4 || mouse_pos == 5 || mouse_pos == 9 || mouse_pos == 10) same_direction = true;
                }
                else if (goalkeeper_pos == 4){
                    if (mouse_pos == 11 || mouse_pos == 12) same_direction = true;
                }
                else if (goalkeeper_pos == 5){
                    if (mouse_pos == 8 || mouse_pos == 13) same_direction = true;
                }
                else if (goalkeeper_pos == 6){
                    if (mouse_pos == 14 || mouse_pos == 15) same_direction = true;
                }
                if (same_direction != true){
                    if (goalkeeper_pos==1) gk_num = 0;
                    else if (goalkeeper_pos==2) gk_num = 1;
                    else if (goalkeeper_pos==3) gk_num = 2;
                    else if (goalkeeper_pos==4) gk_num = 3;
                    else if (goalkeeper_pos==5) gk_num = 1;
                    else if (goalkeeper_pos==6) gk_num = 6;
                }
                if(x>=x_ball){
                    fx=x-370;
                    fy=320-y;
                    bx=fx%10;
                    by=fy%10;
                    if(bx==1)
                        fx-=1;
                    else if(bx==2)
                        fx-=2;
                    else if(bx==3)
                        fx-=3;
                    else if(bx==4)
                        fx-=4;
                    else if(bx==5)
                        fx+=5;
                    else if(bx==6)
                        fx+=4;
                    else if(bx==7)
                        fx+=3;
                    else if(bx==8)
                        fx+=2;
                    else if(bx==9)
                        fx+=1;
                    if(by==1)
                        fy-=1;
                    else if(by==2)
                        fy-=2;
                    else if(by==3)
                        fy-=3;
                    else if(by==4)
                        fy-=4;
                    else if(by==5)
                        fy+=5;
                    else if(by==6)
                        fy+=4;
                    else if(by==7)
                        fy+=3;
                    else if(by==8)
                        fy+=2;
                    else if(by==9)
                        fy+=1;
                    fx=fx/10;
                    fy=fy/10;
                    while(sh<18){
                        if (mouse_pos == 3 && y_gk>135 && same_direction == true){
                            y_gk-=4;
                        }
                        if (mouse_pos == 4 && y_gk>135 && same_direction == true){
                            x_gk+=8;
                            y_gk-=3;
                        }
                        if (mouse_pos == 5 && y_gk>135 && same_direction == true){
                            x_gk+=14;
                            y_gk-=3;
                        }
                        if (mouse_pos == 8 && same_direction == true){
                            y_gk-=1;
                        }
                        if (mouse_pos == 9 && x_gk<584 && same_direction == true){
                            x_gk+=7;
                            y_gk-=1;
                        }
                        if (mouse_pos == 10 && x_gk<=600 && same_direction == true){
                            x_gk+=12;
                            y_gk-=2;
                        }
                        if (mouse_pos == 14 && x_gk<=584 && same_direction == true){
                            x_gk+=9;
                        }
                        if (mouse_pos == 15 && x_gk<=600 && same_direction == true){
                            x_gk+=13;
                        }
                        if (same_direction == false){
                            if (goalkeeper_pos == 1){
                                x_gk-=13;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 2){
                                y_gk-=4;
                            }
                            if (goalkeeper_pos == 3){
                                x_gk+=14;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 4){
                                x_gk-=13;
                                y_gk-=1;
                            }
                            if (goalkeeper_pos == 5){
                                //nothing
                            }
                            if (goalkeeper_pos == 6){
                                x_gk+=14;
                                y_gk-=1;
                            }
                        }
                        if (x_gk+30<468 && x_gk+30>=352 && y_gk+10<190 && y_gk+10>=135 && gk_num == 1) gk_pos = 3; // 60 35
                        else if (x_gk+100<584 && x_gk+100>=468 && y_gk+10<190 && y_gk+10>=135 && gk_num == 2) gk_pos = 4; // 170 45
                        else if (x_gk+100<=700 && x_gk+100>=584 && y_gk+10<190 && y_gk+10>=135 && gk_num == 2) gk_pos = 5; // 170 45
                        else if (x_gk+30<468 && x_gk+30>=352 && y_gk+10<245 && y_gk+10>=190 && gk_num == 1) gk_pos = 8; // 60 35
                        else if (x_gk+180<584 && x_gk+180>=468 && y_gk+40<245 && y_gk+40>=190 && gk_num == 5) gk_pos = 9; // 180 80
                        else if (x_gk+170<=700 && x_gk+170>=584 && y_gk+50<245 && y_gk+50>=190 && gk_num == 6) gk_pos = 10; // 210 100
                        else if (x_gk+30<468 && x_gk+30>=352 && y_gk+100<=300 && y_gk+100>=245 && gk_num == 1) gk_pos = 13; // 60 35
                        else if (x_gk+10<584 && x_gk+10>=468 && y_gk+50<=300 && y_gk+50>=245 && gk_num == 5) gk_pos = 14; // 180 80
                        else if (x_gk+200<=700 && x_gk+200>=584 && y_gk+100<=300 && y_gk+100>=245 && gk_num == 8) gk_pos = 15; // 270 140
                        if(sh%2==0){
                            x_ball+=fx/2;
                            y_ball-=fy/2;
                        }
                        else{
                            x_ball+=fx;
                            y_ball-=fy;
                        }
                        if (gk_pos == 9 && mouse_pos == 14) gk_pos=mouse_pos;
                        if (gk_pos == 8 && mouse_pos == 13) gk_pos=mouse_pos;
                        //std::cout<<gk_pos<<"\t"<<mouse_pos<<"\n";
                        if(y_ball-fy<=y && gk_pos==mouse_pos && x_ball-fx<=x && goal_bool==false){
                            print"Result : Player 2 saved the goal";newline;newline;
                            PlaySound(NULL, 0, 0);
                            PlaySound(TEXT("no_goal.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                            SDL_Rect save_rect = { 0, 0, 800, 400};
                            if(choose_team_2 == 1){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, bc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            else if(choose_team_2 == 2){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            else if(choose_team_2 == 3){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mu_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            else{
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, rm_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            sh=18;
                        }
                        else if(same_direction == false && y_ball-fy<=y && x_ball-fx<=x){
                            print"Result : Player 1 scored the goal";newline;newline;
                            results[8]=1;
                            number++;
                            SDL_Rect score_rect = { 0, 0, 800, 400};
                            SDL_RenderCopy(renderer, score_show, NULL, &score_rect);
                            SDL_Delay(500);
                            SDL_RenderPresent(renderer);
                            SDL_Delay(2000);
                            sh=18;
                        }
                        if(sh>=9)
                            aa-=5*a;
                        else
                            aa-=a;
                        if(h%3==0)
                            a++;
                        sh++;
                        SDL_Rect image_back = { 0, 0, 800, 400 };
                        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                        SDL_RenderPresent(renderer);
                        if (choose_team_2 == 1){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_bc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team_2 == 2){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team_2 == 3){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mu[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else{
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_rm[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
                        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
                        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
                        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
                        if(choose_team == 1){
                            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        if(choose_team == 2){
                            SDL_Rect Man_City_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        if(choose_team == 3){
                            SDL_Rect Man_United_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        if(choose_team == 4){
                            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        if (choose_team_2 == 1){
                            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Rect Man_City_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Rect Man_United_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        else {
                            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        SDL_RenderPresent(renderer);
                        h++;
                        if(h==6)
                            h=1;
                        SDL_Delay(200);
                        if (sh==10){
                            SDL_Delay(200);
                            quit=true;
                        }
                    }
                }
                else if(x<x_ball){
                    fx=370-x;
                    fy=320-y;
                    bx=fx%10;
                    by=fy%10;
                    if(bx==1)
                        fx-=1;
                    else if(bx==2)
                        fx-=2;
                    else if(bx==3)
                        fx-=3;
                    else if(bx==4)
                        fx-=4;
                    else if(bx==5)
                        fx+=5;
                    else if(bx==6)
                        fx+=4;
                    else if(bx==7)
                        fx+=3;
                    else if(bx==8)
                        fx+=2;
                    else if(bx==9)
                        fx+=1;
                    if(by==1)
                        fy-=1;
                    else if(by==2)
                        fy-=2;
                    else if(by==3)
                        fy-=3;
                    else if(by==4)
                        fy-=4;
                    else if(by==5)
                        fy+=5;
                    else if(by==6)
                        fy+=4;
                    else if(by==7)
                        fy+=3;
                    else if(by==8)
                        fy+=2;
                    else if(by==9)
                        fy+=1;
                    fx=fx/10;
                    fy=fy/10;
                    while(sh<18){
                        if (mouse_pos == 1 && x_gk>120 && same_direction == true){
                            x_gk-=14;
                            y_gk-=3;
                        }
                        if (mouse_pos == 2 && y_gk>135 && same_direction == true){
                            x_gk-=5;
                            y_gk-=3;
                        }
                        if (mouse_pos == 6 && x_gk>110 && same_direction == true){
                            x_gk-=12;
                            y_gk-=2;
                        }
                        if (mouse_pos == 7 && x_gk>=236 && same_direction == true){
                            x_gk-=6;
                            y_gk-=1;
                        }
                        if (mouse_pos == 11 && x_gk>120 && same_direction == true){
                            x_gk-=13;
                        }
                        if (mouse_pos == 12 && x_gk>=236 && same_direction == true){
                            x_gk-=7;
                        }
                        if (same_direction == false){
                            if (goalkeeper_pos == 1){
                                x_gk-=13;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 2){
                                y_gk-=4;
                            }
                            if (goalkeeper_pos == 3){
                                x_gk+=14;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 4){
                                x_gk-=13;
                                y_gk-=1;
                            }
                            if (goalkeeper_pos == 5){
                                //nothing
                            }
                            if (goalkeeper_pos == 6){
                                x_gk+=14;
                                y_gk-=1;
                            }
                        }
                        if (x_gk+15<236 && x_gk+15>=120 && y_gk+25<190 && y_gk+25>=135 && gk_num == 0) gk_pos = 1;
                        else if (x_gk+15<352 && x_gk+15>=236 && y_gk+15<190 && y_gk+15>=135 && gk_num == 0) gk_pos = 2;
                        else if (x_gk<236 && x_gk>=120 && y_gk+50<245 && y_gk+50>=190 && gk_num == 3) gk_pos = 6; // 15 100
                        else if (x_gk+10<352 && x_gk+10>=236 && y_gk+50<245 && y_gk+50>=190 && gk_num == 4) gk_pos = 7; // 20 80
                        else if (x_gk<236 && x_gk>=120 && y_gk+70<=300 && y_gk+70>=245 && gk_num == 7) gk_pos = 11; // 35 140
                        else if (x_gk+10<352 && x_gk+10>=236 && y_gk+50<=300 && y_gk+50>=245 && gk_num == 4) gk_pos = 12; // 20 80
                        else if (x_gk+30<468 && x_gk+30>=352 && y_gk+200<=300 && y_gk+200>=245 && gk_num == 1) gk_pos = 13; // 60 35
                        if(sh%2==0){
                            x_ball-=fx/2;
                            y_ball-=fy/2;
                        }
                        else{
                            x_ball-=fx;
                            y_ball-=fy;
                        }
                        //std::cout<<gk_pos<<"\t"<<mouse_pos<<"\n";
                        if (gk_pos == 8 && mouse_pos == 13) gk_pos=mouse_pos;
                        if(y_ball-fy<=y && gk_pos==mouse_pos && x_ball-fx<=x && goal_bool==false){
                            print"Result : Player 2 saved the goal";newline;newline;
                            PlaySound(NULL, 0, 0);
                            SDL_Delay(200);
                            PlaySound(TEXT("no_goal.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                            SDL_Rect save_rect = { 0, 0, 800, 400};
                            if(choose_team_2 == 1){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, bc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            else if(choose_team_2 == 2){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            else if(choose_team_2 == 3){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mu_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            else{
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, rm_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                goal_bool = true;
                                SDL_Delay(3000);
                            }
                            sh=18;
                        }
                        else if(same_direction == false && y_ball-fy<=y && x_ball-fx<=x){
                            print"Result : Player 1 scored the goal";newline;newline;
                            results[8]=1;
                            number++;
                            SDL_Rect score_rect = { 0, 0, 800, 400};
                            SDL_RenderCopy(renderer, score_show, NULL, &score_rect);
                            SDL_Delay(500);
                            SDL_RenderPresent(renderer);
                            SDL_Delay(2000);
                            sh=18;
                        }
                        //std::cout<<number;
                        if(sh>=9)
                            aa-=5*a;
                        else
                            aa-=a;
                        if(h%3==0)
                            a++;
                        sh++;
                        SDL_Rect image_back = { 0, 0, 800, 400 };
                        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                        SDL_RenderPresent(renderer);
                        if (choose_team_2 == 1){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_bc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team_2 == 2){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team_2 == 3){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mu[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else{
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_rm[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
                        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
                        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
                        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
                        if(choose_team == 1){
                            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        if(choose_team == 2){
                            SDL_Rect Man_City_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        if(choose_team == 3){
                            SDL_Rect Man_United_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        if(choose_team == 4){
                            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        if (choose_team_2 == 1){
                            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Rect Man_City_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Rect Man_United_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        else {
                            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        SDL_RenderPresent(renderer);
                        h++;
                        if(h==6)
                            h=1;
                        SDL_Delay(200);
                        if (sh==10){
                            SDL_Delay(200);
                            quit=true;
                        }
                    }
                }
            }
        }
        //SDL_RenderPresent(renderer);
        SDL_Rect image_back = { 0, 0, 800, 400 };
        SDL_Rect ball1 = { 370, 320, 75, 75};
        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
        SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
        if(choose_team == 1){
            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
        }
        if(choose_team == 2){
            SDL_Rect Man_City_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
        }
        if(choose_team == 3){
            SDL_Rect Man_United_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
        }
        if(choose_team == 4){
            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
        }
        if (choose_team_2 == 1){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_bc[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
        }
        else if (choose_team_2 == 2){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mc[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Man_City_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
        }
        else if (choose_team_2 == 3){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mu[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Man_United_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
        }
        else {
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_rm[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
        }
        SDL_RenderPresent(renderer);
        if(voice==1){
            PlaySound(TEXT("cheering.wav"), NULL, SND_NOSTOP|SND_ASYNC);
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    x_ball=370,y_ball=320,fx=0,fy=0,sh=0,h=1,aa=75,a=0;
    x_gk=345,y_gk=200;
    bx=0,by=0;
    x=0,y=0;
    quit = false;
    goal_bool=false;
    first_click_player1=false;
    first_click_player2=false;
    std::cout << "            Turn 10  : Player 2 Is Shooter \n";
    print("Waiting for player 2 to shoot...");
    while (!quit){
        while(SDL_PollEvent(&e) != 0 ){
            if(e.type == SDL_QUIT){
                quit = true;
            }
            else if(e.type == SDL_MOUSEBUTTONDOWN){
                if (first_click_player1==false){
                    first_click_player1=true;
                    for(int i=0;i<32;i++) print"\b";
                    print("Waiting for player 1 to save... ");
                }
                SDL_Rect image_back = { 0, 0, 800, 400 };
                SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                SDL_RenderPresent(renderer);
                int x,y;
                SDL_GetMouseState( &x, &y );
                keydown = false;
                while (!keydown){
                        PlaySound(NULL, 0, 0);
                        PlaySound(TEXT("quite.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
                        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
                        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
                        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
                        if (choose_team == 1){
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_bc[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        else if (choose_team == 2){
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mc[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        else if (choose_team == 3){
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mu[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        else {
                            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_rm[1]);
                            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
                        }
                        if(choose_team == 1){
                            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        if(choose_team == 2){
                            SDL_Rect Man_City_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        if(choose_team == 3){
                            SDL_Rect Man_United_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        if(choose_team == 4){
                            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        if (choose_team_2 == 1){
                            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Rect Man_City_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Rect Man_United_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        else {
                            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                        SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                        SDL_RenderPresent(renderer);
                    while (SDL_PollEvent(&saver)!=0){
                        SDL_WaitEvent(&saver);
                        if (saver.type == SDL_KEYDOWN){
                            if (saver.key.keysym.sym == SDLK_q){
                                keydown = true;
                                goalkeeper_pos = 1;
                            }
                            else if (saver.key.keysym.sym == SDLK_w){
                                keydown = true;
                                goalkeeper_pos = 2;
                            }
                            else if (saver.key.keysym.sym == SDLK_e){
                                keydown = true;
                                goalkeeper_pos = 3;
                            }
                            else if (saver.key.keysym.sym == SDLK_a){
                                keydown = true;
                                goalkeeper_pos = 4;
                            }
                            else if (saver.key.keysym.sym == SDLK_d){
                                keydown = true;
                                goalkeeper_pos = 6;
                            }
                        else{
                            keydown = true;
                            goalkeeper_pos = 5;
                        }
                        if (first_click_player2==false){
                                first_click_player2=true;
                                for(int i=0;i<32;i++) print"\b";
                                print"Both players had decided... Lets see what happen :)";
                                newline;
                            }
                        }
                    }
                }
                if (x<236 && x>=120 && y<190 && y>=135) mouse_pos = 1;
                else if (x<352 && x>=236 && y<190 && y>=135) mouse_pos = 2;
                else if (x<468 && x>=352 && y<190 && y>=135) mouse_pos = 3;
                else if (x<584 && x>=468 && y<190 && y>=135) mouse_pos = 4;
                else if (x<=700 && x>=584 && y<190 && y>=135) mouse_pos = 5;
                else if (x<236 && x>=120 && y<245 && y>=190) mouse_pos = 6;
                else if (x<352 && x>=236 && y<245 && y>=190) mouse_pos = 7;
                else if (x<468 && x>=352 && y<245 && y>=190) mouse_pos = 8;
                else if (x<584 && x>=468 && y<245 && y>=190) mouse_pos = 9;
                else if (x<=700 && x>=584 && y<245 && y>=190) mouse_pos = 10;
                else if (x<236 && x>=120 && y<=300 && y>=245) mouse_pos = 11;
                else if (x<352 && x>=236 && y<=300 && y>=245) mouse_pos = 12;
                else if (x<468 && x>=352 && y<=300 && y>=245) mouse_pos = 13;
                else if (x<584 && x>=468 && y<=300 && y>=245) mouse_pos = 14;
                else if (x<=700 && x>=584 && y<=300 && y>=245) mouse_pos = 15;
                // 1 6 11 // 2 7 12 // 3 8 13 // 4 9 14 // 5 10 15
                if (mouse_pos == 1 || mouse_pos == 2) gk_num = 0;
                else if (mouse_pos == 3 || mouse_pos == 8 || mouse_pos == 13) gk_num = 1;
                else if (mouse_pos == 4 || mouse_pos == 5) gk_num = 2;
                else if (mouse_pos == 6) gk_num = 3;
                else if (mouse_pos == 7 || mouse_pos == 12) gk_num = 4;
                else if (mouse_pos == 9 || mouse_pos == 14) gk_num = 5;
                else if (mouse_pos == 10) gk_num = 6;
                else if (mouse_pos == 11) gk_num = 7;
                else if (mouse_pos == 15) gk_num = 8;
                if(gk_num==0){
                    x_chap=125;
                    y_chap=100;
                }
                else if(gk_num==1){
                    x_chap=100;
                    y_chap=125;
                }
                else if(gk_num==2){
                    x_chap=125;
                    y_chap=100;
                }
                else if(gk_num==3){
                    x_chap=150;
                    y_chap=100;
                }
                else if(gk_num==4){
                    x_chap=107;
                    y_chap=110;
                }
                else if(gk_num==5){
                    x_chap=107;
                    y_chap=110;
                }
                else if(gk_num==6){
                    x_chap=150;
                    y_chap=100;
                }
                else if(gk_num==7){
                    x_chap=150;
                    y_chap=100;
                }
                else if(gk_num==8){
                    x_chap=150;
                    y_chap=100;
                }
                same_direction = false;
                if (goalkeeper_pos == 1){
                    if (mouse_pos == 1 || mouse_pos == 2 || mouse_pos == 6 || mouse_pos == 7) same_direction = true;
                }
                else if (goalkeeper_pos == 2){
                    if (mouse_pos == 3 || mouse_pos == 8) same_direction = true;
                }
                else if (goalkeeper_pos == 3){
                    if (mouse_pos == 4 || mouse_pos == 5 || mouse_pos == 9 || mouse_pos == 10) same_direction = true;
                }
                else if (goalkeeper_pos == 4){
                    if (mouse_pos == 11 || mouse_pos == 12) same_direction = true;
                }
                else if (goalkeeper_pos == 5){
                    if (mouse_pos == 8 || mouse_pos == 13) same_direction = true;
                }
                else if (goalkeeper_pos == 6){
                    if (mouse_pos == 14 || mouse_pos == 15) same_direction = true;
                }
                if (same_direction != true){
                    if (goalkeeper_pos==1) gk_num = 0;
                    else if (goalkeeper_pos==2) gk_num = 1;
                    else if (goalkeeper_pos==3) gk_num = 2;
                    else if (goalkeeper_pos==4) gk_num = 3;
                    else if (goalkeeper_pos==5) gk_num = 1;
                    else if (goalkeeper_pos==6) gk_num = 6;
                }
                if(x>=x_ball){
                    fx=x-370;
                    fy=320-y;
                    bx=fx%10;
                    by=fy%10;
                    if(bx==1)
                        fx-=1;
                    else if(bx==2)
                        fx-=2;
                    else if(bx==3)
                        fx-=3;
                    else if(bx==4)
                        fx-=4;
                    else if(bx==5)
                        fx+=5;
                    else if(bx==6)
                        fx+=4;
                    else if(bx==7)
                        fx+=3;
                    else if(bx==8)
                        fx+=2;
                    else if(bx==9)
                        fx+=1;
                    if(by==1)
                        fy-=1;
                    else if(by==2)
                        fy-=2;
                    else if(by==3)
                        fy-=3;
                    else if(by==4)
                        fy-=4;
                    else if(by==5)
                        fy+=5;
                    else if(by==6)
                        fy+=4;
                    else if(by==7)
                        fy+=3;
                    else if(by==8)
                        fy+=2;
                    else if(by==9)
                        fy+=1;
                    fx=fx/10;
                    fy=fy/10;
                    while(sh<18){
                        if (mouse_pos == 3 && y_gk>135 && same_direction == true){
                            y_gk-=4;
                        }
                        if (mouse_pos == 4 && y_gk>135 && same_direction == true){
                            x_gk+=8;
                            y_gk-=3;
                        }
                        if (mouse_pos == 5 && y_gk>135 && same_direction == true){
                            x_gk+=14;
                            y_gk-=3;
                        }
                        if (mouse_pos == 8 && same_direction == true){
                            y_gk-=1;
                        }
                        if (mouse_pos == 9 && x_gk<584 && same_direction == true){
                            x_gk+=7;
                            y_gk-=1;
                        }
                        if (mouse_pos == 10 && x_gk<=600 && same_direction == true){
                            x_gk+=12;
                            y_gk-=2;
                        }
                        if (mouse_pos == 14 && x_gk<=584 && same_direction == true){
                            x_gk+=9;
                        }
                        if (mouse_pos == 15 && x_gk<=600 && same_direction == true){
                            x_gk+=13;
                        }
                        if (same_direction == false){
                            if (goalkeeper_pos == 1){
                                x_gk-=13;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 2){
                                y_gk-=4;
                            }
                            if (goalkeeper_pos == 3){
                                x_gk+=14;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 4){
                                x_gk-=13;
                                y_gk-=1;
                            }
                            if (goalkeeper_pos == 5){
                                //nothing
                            }
                            if (goalkeeper_pos == 6){
                                x_gk+=14;
                                y_gk-=1;
                            }
                        }
                        if(sh%2==0){
                            x_ball+=fx/2;
                            y_ball-=fy/2;
                        }
                        else{
                            x_ball+=fx;
                            y_ball-=fy;
                        }
                        if(same_direction == true && y_ball-fy<=y && x_ball-fx<=x){
                            print"Result : Player 1 saved the goal";newline;newline;
                            PlaySound(NULL, 0, 0);
                            PlaySound(TEXT("no_goal.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                            SDL_Rect save_rect = { 0, 0, 800, 400};
                            if(choose_team == 1){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, bc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            else if(choose_team == 2){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            else if(choose_team == 3){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mu_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            else{
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, rm_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            sh=18;
                        }
                        else if(same_direction == false && y_ball-fy<=y && x_ball-fx<=x){
                            print"Result : Player 2 scored the goal";newline;newline;
                            results[9]=1;
                            number2++;
                            SDL_Rect score_rect = { 0, 0, 800, 400};
                            SDL_RenderCopy(renderer, score_show, NULL, &score_rect);
                            SDL_Delay(500);
                            SDL_RenderPresent(renderer);
                            SDL_Delay(2000);
                            sh=18;
                        }
                        if(sh>=9)
                            aa-=5*a;
                        else
                            aa-=a;
                        if(h%3==0)
                            a++;
                        sh++;
                        SDL_Rect image_back = { 0, 0, 800, 400 };
                        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                        SDL_RenderPresent(renderer);
                        if (choose_team == 1){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_bc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team == 2){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team == 3){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mu[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else{
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_rm[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
                        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
                        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
                        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
                        //std::cout<<number2;
                        if(choose_team == 1){
                            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        if(choose_team == 2){
                            SDL_Rect Man_City_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        if(choose_team == 3){
                            SDL_Rect Man_United_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        if(choose_team == 4){
                            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        if (choose_team_2 == 1){
                            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Rect Man_City_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Rect Man_United_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        else {
                            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        SDL_RenderPresent(renderer);
                        h++;
                        if(h==6)
                            h=1;
                        SDL_Delay(200);
                        if (sh==10){
                            SDL_Delay(200);
                            quit = true;
                        }
                    }
                }
                else if(x<x_ball){
                    fx=370-x;
                    fy=320-y;
                    bx=fx%10;
                    by=fy%10;
                    if(bx==1)
                        fx-=1;
                    else if(bx==2)
                        fx-=2;
                    else if(bx==3)
                        fx-=3;
                    else if(bx==4)
                        fx-=4;
                    else if(bx==5)
                        fx+=5;
                    else if(bx==6)
                        fx+=4;
                    else if(bx==7)
                        fx+=3;
                    else if(bx==8)
                        fx+=2;
                    else if(bx==9)
                        fx+=1;
                    if(by==1)
                        fy-=1;
                    else if(by==2)
                        fy-=2;
                    else if(by==3)
                        fy-=3;
                    else if(by==4)
                        fy-=4;
                    else if(by==5)
                        fy+=5;
                    else if(by==6)
                        fy+=4;
                    else if(by==7)
                        fy+=3;
                    else if(by==8)
                        fy+=2;
                    else if(by==9)
                        fy+=1;
                    fx=fx/10;
                    fy=fy/10;
                    while(sh<18){
                        if (mouse_pos == 1 && x_gk>120 && same_direction == true){
                            x_gk-=14;
                            y_gk-=3;
                        }
                        if (mouse_pos == 2 && y_gk>135 && same_direction == true){
                            x_gk-=5;
                            y_gk-=3;
                        }
                        if (mouse_pos == 6 && x_gk>120 && same_direction == true){
                            x_gk-=12;
                            y_gk-=2;
                        }
                        if (mouse_pos == 7 && x_gk>=236 && same_direction == true){
                            x_gk-=6;
                            y_gk-=1;
                        }
                        if (mouse_pos == 11 && x_gk>120 && same_direction == true){
                            x_gk-=13;
                        }
                        if (mouse_pos == 12 && x_gk>=236 && same_direction == true){
                            x_gk-=7;
                        }
                        if (same_direction == false){
                            if (goalkeeper_pos == 1){
                                x_gk-=13;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 2){
                                y_gk-=4;
                            }
                            if (goalkeeper_pos == 3){
                                x_gk+=14;
                                y_gk-=6;
                            }
                            if (goalkeeper_pos == 4){
                                x_gk-=13;
                                y_gk-=1;
                            }
                            if (goalkeeper_pos == 5){
                                //nothing
                            }
                            if (goalkeeper_pos == 6){
                                x_gk+=14;
                                y_gk-=1;
                            }
                        }
                        if(sh%2==0){
                            x_ball-=fx/2;
                            y_ball-=fy/2;
                        }
                        else{
                            x_ball-=fx;
                            y_ball-=fy;
                        }
                        if(same_direction == true && y_ball-fy<=y && x_ball-fx<=x){
                            print"Result : Player 1 saved the goal";newline;newline;
                            PlaySound(NULL, 0, 0);
                            PlaySound(TEXT("no_goal.wav"), NULL, SND_NOSTOP|SND_ASYNC);
                            SDL_Rect save_rect = { 0, 0, 800, 400};
                            if(choose_team == 1){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, bc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            else if(choose_team == 2){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mc_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            else if(choose_team == 3){
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, mu_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            else{
                                SDL_Delay(500);
                                SDL_RenderCopy(renderer, rm_save_show, NULL, &save_rect);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(3000);
                            }
                            sh=18;
                        }
                        else if(same_direction == false && y_ball-fy<=y && x_ball-fx<=x){
                            print"Result : Player 2 scored the goal";newline;newline;
                            results[9]=1;
                            number2++;
                            SDL_Rect score_rect = { 0, 0, 800, 400};
                            SDL_RenderCopy(renderer, score_show, NULL, &score_rect);
                            SDL_Delay(500);
                            SDL_RenderPresent(renderer);
                            SDL_Delay(3000);
                            sh=18;
                        }
                        if(sh>=9)
                            aa-=5*a;
                        else
                            aa-=a;
                        if(h%3==0)
                            a++;
                        sh++;
                        SDL_Rect image_back = { 0, 0, 800, 400 };
                        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
                        SDL_RenderPresent(renderer);
                        if (choose_team == 1){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_bc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team == 2){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mc[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else if (choose_team == 3){
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_mu[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        else{
                            SDL_Rect gk_rect = { x_gk, y_gk, x_chap, y_chap};
                            SDL_Texture * first_show = SDL_CreateTextureFromSurface(renderer, gk_rm[gk_num]);
                            SDL_RenderCopy(renderer, first_show, NULL, &gk_rect);
                        if(h==1){
                            SDL_Rect ball2 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball2_show, NULL, &ball2);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==2){
                            SDL_Rect ball3 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball3_show, NULL, &ball3);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==3){
                            SDL_Rect ball4 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball4_show, NULL, &ball4);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==4){
                            SDL_Rect ball5 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball5_show, NULL, &ball5);
                            SDL_RenderPresent(renderer);
                        }
                        if(h==5){
                            SDL_Rect ball1 = {x_ball,y_ball,aa,aa};
                            SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
                            SDL_RenderPresent(renderer);
                        }}
                        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
                        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
                        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
                        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
                        if(choose_team == 1){
                            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        if(choose_team == 2){
                            SDL_Rect Man_City_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        if(choose_team == 3){
                            SDL_Rect Man_United_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        if(choose_team == 4){
                            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        if (choose_team_2 == 1){
                            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
                        }
                        else if (choose_team_2 == 2){
                            SDL_Rect Man_City_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
                        }
                        else if (choose_team_2 == 3){
                            SDL_Rect Man_United_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
                        }
                        else {
                            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
                            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
                        }
                        SDL_RenderPresent(renderer);
                        h++;
                        if(h==6)
                            h=1;
                        SDL_Delay(200);
                        if (sh==10){
                            SDL_Delay(200);
                            quit=true;
                        }
                    }
                }
            }
        }
        SDL_RenderPresent(renderer);
        SDL_Rect image_back = { 0, 0, 800, 400 };
        SDL_Rect ball1 = { 370, 320, 75, 75};
        SDL_RenderCopy(renderer, textureb, NULL, &image_back);
        SDL_RenderCopy(renderer, ball1_show, NULL, &ball1);
        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
        SDL_RenderCopy(renderer, num_show, NULL, &photo1);
        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
        SDL_RenderCopy(renderer, num2_show, NULL, &photo12);
        if (choose_team == 1){
        SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_bc[1]);
        SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
        }
        else if (choose_team == 2){
            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mc[1]);
            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
        }
        else if (choose_team == 3){
            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mu[1]);
            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
        }
        else {
            SDL_Texture * second_gk_show = SDL_CreateTextureFromSurface(renderer, gk_rm[1]);
            SDL_RenderCopy(renderer, second_gk_show, NULL, &first_gk);
        }
        if(choose_team == 1){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_bc[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Barcelona_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
        }
        if(choose_team == 2){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mc[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Man_City_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
        }
        if(choose_team == 3){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_mu[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Man_United_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
        }
        if(choose_team == 4){
            SDL_Texture * first_gk_show = SDL_CreateTextureFromSurface(renderer, gk_rm[1]);
            SDL_RenderCopy(renderer, first_gk_show, NULL, &first_gk);
            SDL_Rect Real_Madrid_text= { 34, 1, 195, 28};
            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
        }
        if (choose_team_2 == 1){
            SDL_Rect Barcelona_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Barcelona_text_show, NULL, &Barcelona_text);
        }
        else if (choose_team_2 == 2){
            SDL_Rect Man_City_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Man_City_text_show, NULL, &Man_City_text);
        }
        else if (choose_team_2 == 3){
            SDL_Rect Man_United_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Man_United_text_show, NULL, &Man_United_text);
        }
        else {
            SDL_Rect Real_Madrid_text= { 34, 51, 195, 28};
            SDL_RenderCopy(renderer, Real_Madrid_text_show, NULL, &Real_Madrid_text);
        }
        SDL_RenderPresent(renderer);
        if(voice==1){
            PlaySound(TEXT("cheering.wav"), NULL, SND_NOSTOP|SND_ASYNC);
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    PlaySound(TEXT("cheering.wav"), NULL, SND_NOSTOP|SND_ASYNC);
    system("cls");
    newline;
    system("echo Players had finished all penalties :D");
    print"Final Results:\n";
    for (int i=0;i<10;i++){
        if (i==9) print "Penalty [" << i+1 << "] : ";
        else print "Penalty [" << i+1 << "]  : ";
        if (results[i]==1) print"scored\n";
        else print"saved\n";
    }
    newline;
    if (number <= 1) print"Player 1 : " << number << " score\n";
    else if (number > 1) print"Player 1 : " << number << " scores\n";
    if (number2 <= 1) print"Player 2 : " << number2 << " scores\n";
    else if (number2 > 1) print"Player 2 : " << number2 << " scores\n";
    SDL_Rect finall_rect={0,0,800,400};
    // bc mc mu rm
    if (choose_team == 1 && choose_team_2 == 2){
        SDL_RenderCopy(renderer, finall_bc, NULL, &finall_rect);
    }
    else if (choose_team == 1 && choose_team_2 == 3){
        SDL_RenderCopy(renderer, finall_bu, NULL, &finall_rect);
    }
    else if (choose_team == 1 && choose_team_2 == 4){
        SDL_RenderCopy(renderer, finall_br, NULL, &finall_rect);
    }
    else if (choose_team == 2 && choose_team_2 == 1){
        opposite = true;
        SDL_RenderCopy(renderer, finall_bc, NULL, &finall_rect);
    }
    else if (choose_team == 2 && choose_team_2 == 3){
        SDL_RenderCopy(renderer, finall_cu, NULL, &finall_rect);
    }
    else if (choose_team == 2 && choose_team_2 == 4){
        SDL_RenderCopy(renderer, finall_cr, NULL, &finall_rect);
    }
    else if (choose_team == 3 && choose_team_2 == 1){
        opposite = true;
        SDL_RenderCopy(renderer, finall_bu, NULL, &finall_rect);
    }
    else if (choose_team == 3 && choose_team_2 == 2){
        opposite = true;
        SDL_RenderCopy(renderer, finall_cu, NULL, &finall_rect);
    }
    else if (choose_team == 3 && choose_team_2 == 4){
        SDL_RenderCopy(renderer, finall_ur, NULL, &finall_rect);
    }
    else if (choose_team == 4 && choose_team_2 == 1){
        opposite = true;
        SDL_RenderCopy(renderer, finall_br, NULL, &finall_rect);
    }
    else if (choose_team == 4 && choose_team_2 == 2){
        opposite = true;
        SDL_RenderCopy(renderer, finall_cr, NULL, &finall_rect);
    }
    else if (choose_team == 4 && choose_team_2 == 3){
        opposite = true;
        SDL_RenderCopy(renderer, finall_ur, NULL, &finall_rect);
    }
    SDL_RenderPresent(renderer);
    SDL_Rect finall_rect_left={330,265,25,45};
    SDL_Rect finall_rect_right={425,265,25,45};
    /*if (opposite == false){
        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
        SDL_RenderCopy(renderer, num_show, NULL, &finall_rect_left);
        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
        SDL_RenderCopy(renderer, num2_show, NULL, &finall_rect_right);
    }
    else{
        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
        SDL_RenderCopy(renderer, num_show, NULL, &finall_rect_right);
        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
        SDL_RenderCopy(renderer, num2_show, NULL, &finall_rect_left);
    }*/
    if (choose_team == 1){
        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
        SDL_RenderCopy(renderer, num_show, NULL, &finall_rect_right);
        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
        SDL_RenderCopy(renderer, num2_show, NULL, &finall_rect_left);
    }
    else if(choose_team == 4 && choose_team_2 == 2){
        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
        SDL_RenderCopy(renderer, num_show, NULL, &finall_rect_right);
        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
        SDL_RenderCopy(renderer, num2_show, NULL, &finall_rect_left);
    }
    else if(choose_team == 4 && choose_team_2 == 3){
        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
        SDL_RenderCopy(renderer, num_show, NULL, &finall_rect_right);
        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
        SDL_RenderCopy(renderer, num2_show, NULL, &finall_rect_left);
    }
    else if(choose_team == 3 && choose_team_2 == 2){
        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
        SDL_RenderCopy(renderer, num_show, NULL, &finall_rect_right);
        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
        SDL_RenderCopy(renderer, num2_show, NULL, &finall_rect_left);
    }
    else {
        SDL_Texture * num_show = SDL_CreateTextureFromSurface(renderer, number_goal[number]);
        SDL_RenderCopy(renderer, num_show, NULL, &finall_rect_left);
        SDL_Texture * num2_show = SDL_CreateTextureFromSurface(renderer, number_goal2[number2]);
        SDL_RenderCopy(renderer, num2_show, NULL, &finall_rect_right);
    }
    SDL_RenderPresent(renderer);
    newline;
    if (number>number2){
        print"Player 1 (";
        switch(choose_team){
        case 1:
            print"Barcelona) won.";
            break;
        case 2:
            print"Manchester City) won.";
            break;
        case 3:
            print"Manchester United) won.";
            break;
        case 4:
            print"Real Madrid) won.";
            break;
        default:
            return 0;
        }
    }
    else if (number2>number){
        print"Player 2 (";
        switch(choose_team_2){
        case 1:
            print"Barcelona) won.";
            break;
        case 2:
            print"Manchester City) won.";
            break;
        case 3:
            print"Manchester United) won.";
            break;
        case 4:
            print"Real Madrid) won.";
            break;
        default:
            return 0;
        }
    }
    else print "What a nice match! No one won (Draw)";
    newline;
    SDL_Delay(20000);
    return 0;
}
