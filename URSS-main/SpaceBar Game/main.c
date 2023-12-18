/*
 * This file is part of the enzofilippo distribution (https://github.com/enzofilippo).
 * Copyright (c) 2021 Enzo Filippo Centenaro da Silva and Vitor Mateus Romancini do Amaral.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define FORMAT_STRING "START Tutorial.pdf"
#define FPS 11.0
#define LARGURA_TELA 640
#define ALTURA_TELA 360

int sair = 0;
int fecharMenu = 0;

double dinheiro = 0;
double custoBaseDormitorio = 10;
double prodBaseDormitorio = 1;
double taxaCrescimentoDormitorio = 1.07;
double custoBaseEstufa = 60;
double prodBaseEstufa = 10;
double taxaCrescimentoEstufa = 1.15;
double custoBaseQuimica = 720;
double prodBaseQuimica = 50;
double taxaCrescimentoQuimica = 1.14;
double custoBaseFisica = 8640;
double prodBaseFisica = 300;
double taxaCrescimentoFisica = 1.13;
double custoBaseRobotica = 103680;
double prodBaseRobotica = 2000;
double taxaCrescimentoRobotica = 1.12;
double custoBaseNuclear = 1300000;
double prodBaseNuclear = 15000;
double taxaCrescimentoNuclear = 1.10;

double custoUpgradeDormitorio = 5000;
double custoUpgradeEstufa = 50000;
double custoUpgradeQuimica = 500000;
double custoUpgradeFisica = 5000000;
double custoUpgradeRobotica = 50000000;
double custoUpgradeNuclear = 500000000;
double custoUpgradeFinal = 5000000000;

double upgradeMultiplierDormitorio = 1;
double upgradeMultiplierEstufa = 1;
double upgradeMultiplierQuimica = 1;
double upgradeMultiplierFisica = 1;
double upgradeMultiplierRobotica = 1;
double upgradeMultiplierNuclear = 1;

float red_x;
float red_y;

double incrementoPorFrame, dinheiroPorSegundo, custo, prod;
double custoDormitorio, custoEstufa, custoQuimica, custoFisica, custoRobotica, custoNuclear;
double qtdeDormitorio, qtdeEstufa, qtdeQuimica, qtdeFisica, qtdeRobotica, qtdeNuclear;
double prodDormitorio, prodEstufa, prodQuimica, prodFisica, prodRobotica, prodNuclear;
int upgradeDormitorio, upgradeEstufa, upgradeQuimica, upgradeFisica, upgradeRobotica, upgradeNuclear, upgradeFinal;

ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_EVENT_QUEUE *filaEventos = NULL;
ALLEGRO_EVENT_QUEUE *filaEventosTimer = NULL;
ALLEGRO_FONT *fonte = NULL;
ALLEGRO_FONT *fonteMenor = NULL;
ALLEGRO_BITMAP *backgroundInterface = NULL;
ALLEGRO_BITMAP *backgroundMenu = NULL;
ALLEGRO_BITMAP *botaoFechar = NULL;
ALLEGRO_BITMAP *botaoFechar2 = NULL;
ALLEGRO_BITMAP *botaoLabs = NULL;
ALLEGRO_BITMAP *botaoLabs2 = NULL;
ALLEGRO_BITMAP *backgroundDinheiro = NULL;
ALLEGRO_BITMAP *backgroundLabs = NULL;
ALLEGRO_BITMAP *backgroundDinheiroPorSegundo = NULL;
ALLEGRO_BITMAP *backgroundMonitor = NULL;
ALLEGRO_BITMAP *botaoUpgradeDormitorio = NULL;
ALLEGRO_BITMAP *botaoUpgradeDormitorio2 = NULL;
ALLEGRO_BITMAP *botaoUpgradeEstufa = NULL;
ALLEGRO_BITMAP *botaoUpgradeEstufa2 = NULL;
ALLEGRO_BITMAP *botaoUpgradeQuimica = NULL;
ALLEGRO_BITMAP *botaoUpgradeQuimica2 = NULL;
ALLEGRO_BITMAP *botaoUpgradeFisica = NULL;
ALLEGRO_BITMAP *botaoUpgradeFisica2 = NULL;
ALLEGRO_BITMAP *botaoUpgradeRobotica = NULL;
ALLEGRO_BITMAP *botaoUpgradeRobotica2 = NULL;
ALLEGRO_BITMAP *botaoUpgradeNuclear = NULL;
ALLEGRO_BITMAP *botaoUpgradeNuclear2 = NULL;
ALLEGRO_BITMAP *botaoUpgradeFinal = NULL;
ALLEGRO_BITMAP *botaoUpgradeFinal2 = NULL;
ALLEGRO_BITMAP *botaoSavegame = NULL;
ALLEGRO_BITMAP *botaoSavegame2 = NULL;
ALLEGRO_BITMAP *botaoNovoJogo = NULL;
ALLEGRO_BITMAP *botaoNovoJogo2 = NULL;
ALLEGRO_BITMAP *labInicial = NULL;
ALLEGRO_BITMAP *labDormitorio = NULL;
ALLEGRO_BITMAP *labEstufa = NULL;
ALLEGRO_BITMAP *labQuimica = NULL;
ALLEGRO_BITMAP *labFisica = NULL;
ALLEGRO_BITMAP *labRobotica = NULL;
ALLEGRO_BITMAP *labNuclear = NULL;
ALLEGRO_BITMAP *labDormitorioUpgrade = NULL;
ALLEGRO_BITMAP *labEstufaUpgrade = NULL;
ALLEGRO_BITMAP *labQuimicaUpgrade = NULL;
ALLEGRO_BITMAP *labFisicaUpgrade = NULL;
ALLEGRO_BITMAP *labRoboticaUpgrade = NULL;
ALLEGRO_BITMAP *labNuclearUpgrade = NULL;
ALLEGRO_BITMAP *satelite = NULL;
ALLEGRO_BITMAP *satelite2 = NULL;
ALLEGRO_BITMAP *led = NULL;
ALLEGRO_BITMAP *botaoMenuNovojogo = NULL;
ALLEGRO_BITMAP *botaoMenuNovojogo2 = NULL;
ALLEGRO_BITMAP *botaoMenu1Jogador = NULL;
ALLEGRO_BITMAP *botaoMenu2Jogador = NULL;
ALLEGRO_BITMAP *botaoMenuJogador2 = NULL;
ALLEGRO_BITMAP *botaoMenuContinuar = NULL;
ALLEGRO_BITMAP *botaoMenuContinuar2 = NULL;
ALLEGRO_BITMAP *botaoMenuTutorial = NULL;
ALLEGRO_BITMAP *botaoMenuTutorial2 = NULL;
ALLEGRO_BITMAP *botaoMenuSair = NULL;
ALLEGRO_BITMAP *botaoMenuSair2 = NULL;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_SAMPLE *som_botao = NULL;
ALLEGRO_SAMPLE *som_semDinheiro = NULL;
ALLEGRO_SAMPLE *som_satelite = NULL;
ALLEGRO_AUDIO_STREAM *musica = NULL;

FILE *save;

int novoJogo, noBotaoFecharAnterior, noBotaoLabsAnterior, noBotaoSateliteAnterior, noBotaoSavegameAnterior, noBotaoNovoJogoAnterior, noBotaoAnteriorUD, noBotaoAnteriorUE, noBotaoAnteriorUQ, noBotaoAnteriorUF, noBotaoAnteriorUR, noBotaoAnteriorUN, noBotaoAnteriorUO;

void error_msg(char *text){
	al_show_native_message_box(NULL,"ERRO",
		"Ocorreu o seguinte erro e o programa sera finalizado:",
		text,NULL,ALLEGRO_MESSAGEBOX_ERROR);
}

double custo_calculo(double custoBase, double qtde, double taxaCrescimento){
    custo = custoBase*pow(taxaCrescimento,qtde);
    return custo;
}

double prod_calculo(double prodBase, double qtde, double multiplier){
    prod = (prodBase*qtde)*multiplier;
    return prod;
}

int saveGame(double d,
             double uMD,
             double uME,
             double uMQ,
             double uMF,
             double uMR,
             double uMN,
             double qD,
             double qE,
             double qQ,
             double qF,
             double qR,
             double qN,
             int uD,
             int uE,
             int uQ,
             int uF,
             int uR,
             int uN,
             int uO){

    save = fopen("save.txt","w");
    fprintf(save,"%.2f\n",d);
    fprintf(save,"%.2f\n",uMD);
    fprintf(save,"%.2f\n",uME);
    fprintf(save,"%.2f\n",uMQ);
    fprintf(save,"%.2f\n",uMF);
    fprintf(save,"%.2f\n",uMR);
    fprintf(save,"%.2f\n",uMN);
    fprintf(save,"%.2f\n",qD);
    fprintf(save,"%.2f\n",qE);
    fprintf(save,"%.2f\n",qQ);
    fprintf(save,"%.2f\n",qF);
    fprintf(save,"%.2f\n",qR);
    fprintf(save,"%.2f\n",qN);
    fprintf(save,"%d\n",uD);
    fprintf(save,"%d\n",uE);
    fprintf(save,"%d\n",uQ);
    fprintf(save,"%d\n",uF);
    fprintf(save,"%d\n",uR);
    fprintf(save,"%d\n",uN);
    fprintf(save,"%d\n",uO);
    fclose(save);

    return 0;
}

int interface_game(){

    double dadosSave[20], dado;
    save = fopen("save.txt","r");
    for(int i=0;i<20;i++){
        fscanf(save,"%lf",&dado);
        dadosSave[i] = dado;
    }
    fclose(save);

    dinheiro = dadosSave[0];
    upgradeMultiplierDormitorio = dadosSave[1];
    upgradeMultiplierEstufa = dadosSave[2];
    upgradeMultiplierQuimica = dadosSave[3];
    upgradeMultiplierFisica = dadosSave[4];
    upgradeMultiplierRobotica = dadosSave[5];
    upgradeMultiplierNuclear = dadosSave[6];
    qtdeDormitorio = dadosSave[7];
    qtdeEstufa = dadosSave[8];
    qtdeQuimica= dadosSave[9];
    qtdeFisica= dadosSave[10];
    qtdeRobotica= dadosSave[11];
    qtdeNuclear= dadosSave[12];
    upgradeDormitorio= dadosSave[13];
    upgradeEstufa= dadosSave[14];
    upgradeQuimica= dadosSave[15];
    upgradeFisica= dadosSave[16];
    upgradeRobotica= dadosSave[17];
    upgradeNuclear= dadosSave[18];
    upgradeFinal= dadosSave[19];
    prodDormitorio = prod_calculo(prodBaseDormitorio, qtdeDormitorio, upgradeMultiplierDormitorio);
    prodEstufa = prod_calculo(prodBaseEstufa, qtdeEstufa, upgradeMultiplierEstufa);
    prodQuimica = prod_calculo(prodBaseQuimica, qtdeQuimica, upgradeMultiplierQuimica);
    prodFisica = prod_calculo(prodBaseFisica, qtdeFisica, upgradeMultiplierFisica);
    prodRobotica = prod_calculo(prodBaseRobotica, qtdeRobotica, upgradeMultiplierRobotica);
    prodNuclear = prod_calculo(prodBaseNuclear, qtdeNuclear, upgradeMultiplierNuclear);
    custoDormitorio = custo_calculo(custoBaseDormitorio, qtdeDormitorio, taxaCrescimentoDormitorio);
    custoEstufa = custo_calculo(custoBaseEstufa, qtdeEstufa, taxaCrescimentoEstufa);
    custoQuimica = custo_calculo(custoBaseQuimica, qtdeQuimica, taxaCrescimentoQuimica);
    custoFisica = custo_calculo(custoBaseFisica, qtdeFisica, taxaCrescimentoFisica);
    custoRobotica = custo_calculo(custoBaseRobotica, qtdeRobotica, taxaCrescimentoRobotica);
    custoNuclear = custo_calculo(custoBaseNuclear, qtdeNuclear, taxaCrescimentoNuclear);

    al_draw_bitmap(backgroundInterface, 0, 0, 0);
    al_draw_bitmap(labInicial, 259, 32, 0);

    if(upgradeDormitorio){
        al_draw_bitmap(led, 555, 50, 0);
    }
    if(upgradeEstufa){
        al_draw_bitmap(led, 555, 77, 0);
    }
    if(upgradeQuimica){
        al_draw_bitmap(led, 555, 104, 0);
    }
    if(upgradeFisica){
        al_draw_bitmap(led, 555, 131, 0);
    }
    if(upgradeRobotica){
        al_draw_bitmap(led, 555, 158, 0);
    }
    if(upgradeNuclear){
        al_draw_bitmap(led, 555, 185, 0);
    }
    if(upgradeFinal){
        al_draw_bitmap(led, 555, 212, 0);
    }

    al_draw_textf(fonteMenor, al_map_rgb(55, 68, 89), 53, 277, ALLEGRO_ALIGN_LEFT, "DORMITORIO: %.0f", qtdeDormitorio);
    al_draw_textf(fonteMenor, al_map_rgb(55, 68, 89), 53, 287, ALLEGRO_ALIGN_LEFT, "custo: %.2f", custoDormitorio);
    al_draw_textf(fonteMenor, al_map_rgb(55, 68, 89), 53, 305, ALLEGRO_ALIGN_LEFT, "ESTUFA: %.0f", qtdeEstufa);
    al_draw_textf(fonteMenor, al_map_rgb(55, 68, 89), 53, 315, ALLEGRO_ALIGN_LEFT, "custo: %.2f", custoEstufa);
    al_draw_textf(fonteMenor, al_map_rgb(55, 68, 89), 53, 333, ALLEGRO_ALIGN_LEFT, "QUIMICA: %.0f", qtdeQuimica);
    al_draw_textf(fonteMenor, al_map_rgb(55, 68, 89), 53, 343, ALLEGRO_ALIGN_LEFT, "custo: %.2f", custoQuimica);
    al_draw_textf(fonteMenor, al_map_rgb(55, 68, 89), 216, 277, ALLEGRO_ALIGN_LEFT, "FISICA: %.0f", qtdeFisica);
    al_draw_textf(fonteMenor, al_map_rgb(55, 68, 89), 216, 287, ALLEGRO_ALIGN_LEFT, "custo: %.2f", custoFisica);
    al_draw_textf(fonteMenor, al_map_rgb(55, 68, 89), 216, 305, ALLEGRO_ALIGN_LEFT, "ROBOTICA: %.0f", qtdeRobotica);
    al_draw_textf(fonteMenor, al_map_rgb(55, 68, 89), 216, 315, ALLEGRO_ALIGN_LEFT, "custo: %.2f", custoRobotica);
    al_draw_textf(fonteMenor, al_map_rgb(55, 68, 89), 216, 333, ALLEGRO_ALIGN_LEFT, "NUCLEAR: %.0f", qtdeNuclear);
    al_draw_textf(fonteMenor, al_map_rgb(55, 68, 89), 216, 343, ALLEGRO_ALIGN_LEFT, "custo: %.2f", custoNuclear);

    if(qtdeDormitorio>0){
        al_draw_bitmap(labDormitorio, 280, 36, 0);
    }
    if(qtdeEstufa>0){
        al_draw_bitmap(labEstufa, 6, 139, 0);
    }
    if(qtdeQuimica>0){
        al_draw_bitmap(labQuimica, 119, 41, 0);
    }
    if(qtdeFisica>0){
        al_draw_bitmap(labFisica, 8, 41, 0);
    }
    if(qtdeRobotica>0){
        al_draw_bitmap(labRobotica, 204, 148, 0);
    }
    if(qtdeNuclear>0){
        al_draw_bitmap(labNuclear, 349, 131, 0);
    }

    al_flip_display();

    return 1;
}

int interface_menu(){
    al_draw_bitmap(backgroundMenu, 0, 0, 0);

    while(!fecharMenu){

        al_flip_display();

        while(!al_is_event_queue_empty(filaEventos)){ //eventos de mouse
            ALLEGRO_EVENT evento;
            al_wait_for_event(filaEventos, &evento);

            if(novoJogo){
                if (evento.mouse.x >= red_x*209 &&  //bot�o menu 1 jogador
                    evento.mouse.x <= red_x*319 &&
                    evento.mouse.y <= red_y*158 &&
                    evento.mouse.y >= red_y*141) {

                    al_draw_bitmap(botaoMenu1Jogador, 209, 141, 0);
                    noBotaoFecharAnterior = 1;

                    if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                        al_play_sample(som_botao, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                        noBotaoFecharAnterior = 1;
                        saveGame(0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0);
                        novoJogo=0;
                        fecharMenu=1;
                    }
                }else{
                    if (evento.mouse.x >= red_x*324 &&  //bot�o menu 2 jogador
                        evento.mouse.x <= red_x*460 &&
                        evento.mouse.y <= red_y*158 &&
                        evento.mouse.y >= red_y*141) {

                        al_draw_bitmap(botaoMenu2Jogador, 209, 141, 0);
                        noBotaoFecharAnterior = 1;

                        if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                            al_play_sample(som_botao, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                            noBotaoFecharAnterior = 1;
                            al_show_native_message_box(janela, "Você não possui a DLC Ultimate Multiplayer!","Conteúdo bloqueado por DLC Paga.","Compre a DLC Ultimate Multiplayer, por 1999 suaves prestações de 17 centavos!",NULL,ALLEGRO_MESSAGEBOX_WARN);
                            al_draw_bitmap(backgroundMenu, 0, 0, 0);
                            novoJogo=0;
                        }
                    }else{
                        if(noBotaoFecharAnterior){
                        al_draw_bitmap(botaoMenuJogador2, 209, 141, 0);
                        }
                    }
                }

            }else{
            if (evento.mouse.x >= red_x*241 &&  //bot�o menu novo jogo
                evento.mouse.x <= red_x*399 &&
                evento.mouse.y <= red_y*158 &&
                evento.mouse.y >= red_y*141) {

                al_draw_bitmap(botaoMenuNovojogo, 241, 141, 0);
                noBotaoFecharAnterior = 1;

                if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                    al_play_sample(som_botao, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                    noBotaoFecharAnterior = 1;
                    al_draw_bitmap(botaoMenuJogador2,209,141,0);
                    novoJogo=1;
                }
            }else{
                if(noBotaoFecharAnterior){
                    al_draw_bitmap(botaoMenuNovojogo2, 241, 141, 0);
                }
            }
            }

            if (evento.mouse.x >= red_x*238 &&  //bot�o menu continuar
                evento.mouse.x <= red_x*402 &&
                evento.mouse.y <= red_y*188 &&
                evento.mouse.y >= red_y*171) {

                al_draw_bitmap(botaoMenuContinuar, 238, 171, 0);
                noBotaoFecharAnterior = 1;

                if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                    al_play_sample(som_botao, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                    noBotaoFecharAnterior = 1;
                    fecharMenu=1;
                }
            }else{
                if(noBotaoFecharAnterior){
                    al_draw_bitmap(botaoMenuContinuar2, 238, 171, 0);
                }
            }

            if (evento.mouse.x >= red_x*248 &&  //bot�o menu tutorial
                evento.mouse.x <= red_x*391 &&
                evento.mouse.y <= red_y*218 &&
                evento.mouse.y >= red_y*201) {

                al_draw_bitmap(botaoMenuTutorial, 248, 201, 0);
                noBotaoFecharAnterior = 1;

                if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                    al_play_sample(som_botao, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                    size_t len = snprintf(NULL, 0, FORMAT_STRING) + 1;
                    char *cmd = malloc(len*sizeof(char));
                    snprintf(cmd, len, FORMAT_STRING);
                    system(cmd);
                    free(cmd);
                }
            }else{
                if(noBotaoFecharAnterior){
                    al_draw_bitmap(botaoMenuTutorial2, 248, 201, 0);
                }
            }

            if (evento.mouse.x >= red_x*287 &&  //bot�o para sair
                evento.mouse.x <= red_x*352 &&
                evento.mouse.y <= red_y*248 &&
                evento.mouse.y >= red_y*231) {

                al_draw_bitmap(botaoMenuSair, 287, 231, 0);
                noBotaoFecharAnterior = 1;

                if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                sair = 1;
                fecharMenu = 1;
                }
            }else{
                if(noBotaoFecharAnterior){
                    al_draw_bitmap(botaoMenuSair2, 287, 231, 0);
                }
            }

        }
    }
    return 1;
}

int inicializar(){
    if (!al_init()){
        error_msg("Falha ao inicializar a Allegro");
        return 0;
    }

    if(!al_install_audio()){
        error_msg("Falha ao inicializar o audio");
        return 0;
    }

    if(!al_init_acodec_addon()){
        error_msg("Falha ao inicializar o codec de audio");
        return 0;
    }

    if (!al_reserve_samples(5)){
        error_msg("Falha ao reservar amostrar de audio");
        return 0;
    }

    som_botao = al_load_sample( "assets/buttonSound.ogg" );
    if (!som_botao){
        error_msg( "Audio nao carregado" );
        return 0;
    }

    som_semDinheiro = al_load_sample( "assets/semDinheiro.ogg" );
    if (!som_botao){
        error_msg( "Audio nao carregado" );
        al_destroy_sample(som_botao);
        return 0;
    }

    som_satelite = al_load_sample( "assets/satelite.ogg" );
    if (!som_satelite){
        error_msg( "Audio nao carregado" );
        al_destroy_sample(som_botao);
        al_destroy_sample(som_semDinheiro);
        return 0;
    }

    musica = al_load_audio_stream("assets/soundtrack.ogg", 4, 1024);
    if (!musica){
        al_destroy_sample(som_botao);
        al_destroy_sample(som_semDinheiro);
        al_destroy_sample(som_satelite);
        error_msg( "Audio nao carregado" );
        return 0;
    }

    al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
    al_set_audio_stream_playmode(musica, ALLEGRO_PLAYMODE_LOOP);

    timer = al_create_timer(1.0 / FPS);
    if(!timer) {
        error_msg("Falha ao criar temporizador");
        return 0;
    }

    al_init_font_addon();

    if (!al_init_ttf_addon()){
        error_msg("Falha ao inicializar add-on allegro_ttf");
        return 0;
    }

    if (!al_init_image_addon()){
        error_msg("Falha ao inicializar add-on allegro_image");
        return 0;
    }

    if (!al_install_keyboard()){
        error_msg("Falha ao inicializar o teclado");
        return 0;
    }

    ALLEGRO_MONITOR_INFO info;
	int res_x_comp, res_y_comp;
	al_get_monitor_info(0, &info);
	res_x_comp = info.x2 - info.x1;
	res_y_comp = info.y2 - info.y1;
	al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
	janela = al_create_display(res_x_comp, res_y_comp);

    //janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela){
        error_msg("Falha ao criar janela");
        return 0;
    }

    red_x = res_x_comp / (float)LARGURA_TELA;
	red_y = res_y_comp / (float)ALTURA_TELA;
	ALLEGRO_TRANSFORM transformar;
	al_identity_transform(&transformar);
	al_scale_transform(&transformar, red_x, red_y);
	al_use_transform(&transformar);

    if (!al_install_mouse()){
        error_msg("Falha ao inicializar o mouse");
        al_destroy_display(janela);
        return -1;
    }

    if (!al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT)){
        error_msg("Falha ao atribuir ponteiro do mouse");
        al_destroy_display(janela);
        return -1;
    }

    al_set_window_title(janela, "Ultimate Restless Space Station - Feito por Enzo Filippo Centenaro e Vitor Mateus Romancini");

    fonte = al_load_font("assets/gamer.ttf", 32, 0);
    if (!fonte){
        error_msg("Falha ao carregar \"assets/gamer.ttf\"");
        al_destroy_display(janela);
        return 0;
    }
    fonteMenor = al_load_font("assets/gamer.ttf", 16, 0);
    if (!fonte){
        error_msg("Falha ao carregar \"assets/gamer.ttf\"");
        al_destroy_display(janela);
        return 0;
    }

    filaEventos = al_create_event_queue();
    if (!filaEventos){
        error_msg("Falha ao criar fila de eventos");
        al_destroy_display(janela);
        return 0;
    }
    filaEventosTimer = al_create_event_queue();
    if (!filaEventos){
        error_msg("Falha ao criar fila de eventos");
        al_destroy_display(janela);
        return 0;
    }

    backgroundInterface = al_load_bitmap("assets/background_interface.png");
    backgroundMenu = al_load_bitmap("assets/background_menu.png");
    botaoFechar = al_load_bitmap("assets/sprite_botao_fechar.png");
    botaoFechar2 = al_load_bitmap("assets/sprite_botao_fechar_2.png");
    botaoLabs = al_load_bitmap("assets/sprite_botao_labs.png");
    botaoLabs2 = al_load_bitmap("assets/sprite_botao_labs_2.png");
    backgroundDinheiro = al_load_bitmap("assets/background_dinheiro.png");
    backgroundLabs = al_load_bitmap("assets/background_lab.png");
    backgroundDinheiroPorSegundo = al_load_bitmap("assets/background_dinheiroporsegundo.png");
    backgroundMonitor = al_load_bitmap("assets/background_monitor.png");
    botaoUpgradeDormitorio = al_load_bitmap("assets/sprite_upgrade_dormitorio.png");
    botaoUpgradeDormitorio2 = al_load_bitmap("assets/sprite_upgrade_dormitorio_2.png");
    botaoUpgradeEstufa = al_load_bitmap("assets/sprite_upgrade_estufa.png");
    botaoUpgradeEstufa2 = al_load_bitmap("assets/sprite_upgrade_estufa_2.png");
    botaoUpgradeQuimica = al_load_bitmap("assets/sprite_upgrade_quimica.png");
    botaoUpgradeQuimica2 = al_load_bitmap("assets/sprite_upgrade_quimica_2.png");
    botaoUpgradeFisica = al_load_bitmap("assets/sprite_upgrade_fisica.png");
    botaoUpgradeFisica2 = al_load_bitmap("assets/sprite_upgrade_fisica_2.png");
    botaoUpgradeRobotica = al_load_bitmap("assets/sprite_upgrade_robotica.png");
    botaoUpgradeRobotica2 = al_load_bitmap("assets/sprite_upgrade_robotica_2.png");
    botaoUpgradeNuclear = al_load_bitmap("assets/sprite_upgrade_nuclear.png");
    botaoUpgradeNuclear2 = al_load_bitmap("assets/sprite_upgrade_nuclear_2.png");
    botaoUpgradeFinal = al_load_bitmap("assets/sprite_upgrade_final.png");
    botaoUpgradeFinal2 = al_load_bitmap("assets/sprite_upgrade_final_2.png");
    botaoSavegame = al_load_bitmap("assets/sprite_botao_savegame.png");
    botaoSavegame2 = al_load_bitmap("assets/sprite_botao_savegame_2.png");
    botaoNovoJogo = al_load_bitmap("assets/sprite_botao_novojogo.png");
    botaoNovoJogo2 = al_load_bitmap("assets/sprite_botao_novojogo_2.png");
    led = al_load_bitmap("assets/sprite_luz_ligada.png");
    labInicial = al_load_bitmap("assets/lab_inicial.png");
    labDormitorio = al_load_bitmap("assets/lab_dormitorio.png");
    labEstufa = al_load_bitmap("assets/lab_estufa.png");
    labQuimica = al_load_bitmap("assets/lab_quimica.png");
    labFisica = al_load_bitmap("assets/lab_fisica.png");
    labRobotica = al_load_bitmap("assets/lab_robotica.png");
    labNuclear = al_load_bitmap("assets/lab_nuclear.png");
    labDormitorioUpgrade = al_load_bitmap("assets/lab_dormitorio_upgrade.png");
    labEstufaUpgrade = al_load_bitmap("assets/lab_estufa_upgrade.png");
    labQuimicaUpgrade = al_load_bitmap("assets/lab_quimica_upgrade.png");
    labFisicaUpgrade = al_load_bitmap("assets/lab_fisica_upgrade.png");
    labRoboticaUpgrade = al_load_bitmap("assets/lab_robotica_upgrade.png");
    labNuclearUpgrade = al_load_bitmap("assets/lab_nuclear_upgrade.png");
    satelite = al_load_bitmap("assets/sprite_satelite.png");
    satelite2 = al_load_bitmap("assets/sprite_satelite_2.png");
    botaoMenuNovojogo = al_load_bitmap("assets/sprite_botao_menu_novojogo.png");
    botaoMenuNovojogo2 = al_load_bitmap("assets/sprite_botao_menu_novojogo_2.png");
    botaoMenuContinuar = al_load_bitmap("assets/sprite_botao_menu_continuar.png");
    botaoMenu1Jogador = al_load_bitmap("assets/sprite_botao_menu_1jogador.png");
    botaoMenu2Jogador = al_load_bitmap("assets/sprite_botao_menu_2jogador.png");
    botaoMenuJogador2 = al_load_bitmap("assets/sprite_botao_menu_jogador_2.png");
    botaoMenuContinuar2 = al_load_bitmap("assets/sprite_botao_menu_continuar_2.png");
    botaoMenuTutorial = al_load_bitmap("assets/sprite_botao_menu_tutorial.png");
    botaoMenuTutorial2 = al_load_bitmap("assets/sprite_botao_menu_tutorial_2.png");
    botaoMenuSair = al_load_bitmap("assets/sprite_botao_menu_sair.png");
    botaoMenuSair2 = al_load_bitmap("assets/sprite_botao_menu_sair_2.png");

    al_register_event_source(filaEventos, al_get_keyboard_event_source());
    al_register_event_source(filaEventos, al_get_display_event_source(janela));
    al_register_event_source(filaEventos, al_get_mouse_event_source());
    al_register_event_source(filaEventosTimer, al_get_timer_event_source(timer));

    al_start_timer(timer);

    return 1;
}

int main(void){

    if(!inicializar()){
        return -1;
    }

    if(!interface_menu()){
        return -1;
    }

    if(!interface_game()){
        return -1;
    }

    while(!sair){

        while(!al_is_event_queue_empty(filaEventos)){ //eventos de mouse
            ALLEGRO_EVENT evento;
            al_wait_for_event(filaEventos, &evento);

            if (evento.mouse.x >= red_x*6 &&  //bot�o para fechar o jogo
                evento.mouse.x <= red_x*21 &&
                evento.mouse.y <= red_y*21 &&
                evento.mouse.y >= red_y*6) {

                al_draw_bitmap(botaoFechar, 6, 6, 0);
                al_draw_bitmap(backgroundMonitor, 390, 274, 0);
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,273 , ALLEGRO_ALIGN_LEFT, "Sério que você vai");
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,285 , ALLEGRO_ALIGN_LEFT, "fechar o jogo? AFF");
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,297 , ALLEGRO_ALIGN_LEFT, "Vou chamar o Putin");
                noBotaoFecharAnterior = 1;

                if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                sair = 1;
                }
            }else{
                if(noBotaoFecharAnterior){
                    al_draw_bitmap(botaoFechar2, 6, 6, 0);
                    al_draw_bitmap(backgroundMonitor, 390, 274, 0);
                    al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,273 , ALLEGRO_ALIGN_LEFT, "Não sei o que seria");
                    al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,285 , ALLEGRO_ALIGN_LEFT, "da estação sem você ");
                    al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,297 , ALLEGRO_ALIGN_LEFT, "camarada! <3");
                }
            }

            if (evento.mouse.x >= red_x*622 &&  //bot�o para clicar no savegame
                evento.mouse.x <= red_x*635 &&
                evento.mouse.y <= red_y*268 &&
                evento.mouse.y >= red_y*255) {

                noBotaoSavegameAnterior = 1;
                al_draw_bitmap(botaoSavegame, 622, 255, 0);
                al_draw_bitmap(backgroundMonitor, 390, 274, 0);
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,273 , ALLEGRO_ALIGN_LEFT, "Clique para salvar o ");
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,285 , ALLEGRO_ALIGN_LEFT, "seu progresso, imagina");
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,297 , ALLEGRO_ALIGN_LEFT, "perder tudo!");

                if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                    al_play_sample(som_botao, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                    saveGame(dinheiro,
                             upgradeMultiplierDormitorio,
                             upgradeMultiplierEstufa,
                             upgradeMultiplierQuimica,
                             upgradeMultiplierFisica,
                             upgradeMultiplierRobotica,
                             upgradeMultiplierNuclear,
                             qtdeDormitorio,
                             qtdeEstufa,
                             qtdeQuimica,
                             qtdeFisica,
                             qtdeRobotica,
                             qtdeNuclear,
                             upgradeDormitorio,
                             upgradeEstufa,
                             upgradeQuimica,
                             upgradeFisica,
                             upgradeRobotica,
                             upgradeNuclear,
                             upgradeFinal);
                }
            }else{
                if(noBotaoSavegameAnterior){
                    al_draw_bitmap(botaoSavegame2, 622, 255, 0);
                }
            }

            if (evento.mouse.x >= red_x*608 &&  //bot�o para clicar no novojogo
                evento.mouse.x <= red_x*631 &&
                evento.mouse.y <= red_y*314 &&
                evento.mouse.y >= red_y*291) {

                noBotaoNovoJogoAnterior = 1;
                al_draw_bitmap(botaoNovoJogo , 608, 280, 0);

                if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                    int iniciarNovoJogo = al_show_native_message_box(
                        janela,
                        "URSS - Ultimate Restless Space Station",
                        "Previet Camarada",
                        "Tem certeza que quer nos abandonar? "
                        "Ficaremos a mercê do esquecimento eterno, "
                        "ou pior, dos capitalistas! "
                        "Escolha com sabedoria. Tudo que foi salvo será apagado.",
                        NULL,
                        ALLEGRO_MESSAGEBOX_YES_NO
                        );
                    if (iniciarNovoJogo){
                        al_play_sample(som_botao, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                        saveGame(0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0);
                        al_destroy_sample(som_botao);
                        al_destroy_audio_stream(musica);
                        al_destroy_timer(timer);
                        al_destroy_font(fonte);
                        al_destroy_display(janela);
                        al_destroy_event_queue(filaEventos);
                        al_destroy_event_queue(filaEventosTimer);
                        inicializar();
                        interface_game();
                    }

                }
            }else{
                if(noBotaoNovoJogoAnterior){
                    al_draw_bitmap(botaoNovoJogo2, 608, 280, 0);
                }
            }

            if (evento.mouse.x >= red_x*263 &&  //bot�o para clicar no satélite
                evento.mouse.x <= red_x*281 &&
                evento.mouse.y <= red_y*146 &&
                evento.mouse.y >= red_y*128) {

                noBotaoSateliteAnterior = 1;

                if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                    al_play_sample(som_satelite, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                    al_draw_bitmap(satelite, 263, 128, 0);
                    dinheiro += (upgradeMultiplierDormitorio*upgradeMultiplierEstufa*upgradeMultiplierQuimica*upgradeMultiplierFisica*upgradeMultiplierRobotica*upgradeMultiplierNuclear);
                    al_draw_bitmap(backgroundDinheiro, 263, 6, 0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA_TELA - 38, 0, ALLEGRO_ALIGN_RIGHT, "%.2f", dinheiro);

                }
            }else{
                if(noBotaoSateliteAnterior){
                    al_draw_bitmap(satelite2, 263, 128, 0);
                }
            }

            if (evento.mouse.x >= red_x*2 &&  //bot�o para comprar dormit�rio
                evento.mouse.x <= red_x*21 &&
                evento.mouse.y <= red_y*299 &&
                evento.mouse.y >= red_y*279) {

                al_draw_bitmap(backgroundMonitor, 390, 274, 0);
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,273 , ALLEGRO_ALIGN_LEFT, "O que será que esse");
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,285 , ALLEGRO_ALIGN_LEFT, "botão faz?");
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,297 , ALLEGRO_ALIGN_LEFT, "");
                al_draw_bitmap(botaoLabs, 2, 279, 0);
                noBotaoLabsAnterior = 1;

                if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                    custoDormitorio = custo_calculo(custoBaseDormitorio, qtdeDormitorio, taxaCrescimentoDormitorio);
                    if(custoDormitorio<=dinheiro){
                        al_play_sample(som_botao, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                        qtdeDormitorio += 1;
                        if(qtdeDormitorio==1){
                            al_draw_bitmap(labDormitorio, 280, 36, 0);
                        }
                        dinheiro -= custoDormitorio;
                        prodDormitorio = prod_calculo(prodBaseDormitorio, qtdeDormitorio, upgradeMultiplierDormitorio);
                        al_draw_bitmap(backgroundLabs, 53, 279, 0);
                        al_draw_textf(fonteMenor, al_map_rgb(55, 68, 89), 53, 277, ALLEGRO_ALIGN_LEFT, "DORMITORIO: %.0f", qtdeDormitorio);
                        custoDormitorio = custo_calculo(custoBaseDormitorio, qtdeDormitorio, taxaCrescimentoDormitorio);
                        al_draw_textf(fonteMenor, al_map_rgb(55, 68, 89), 53, 287, ALLEGRO_ALIGN_LEFT, "custo: %.2f", custoDormitorio);
                        al_draw_bitmap(backgroundMonitor, 390, 274, 0);
                        al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,273 , ALLEGRO_ALIGN_LEFT, "Eu nem sabia que tinha");
                        al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,285 , ALLEGRO_ALIGN_LEFT, "camas no espaço...");
                        al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,297 , ALLEGRO_ALIGN_LEFT, "Mas foi você que pagou");
                    }else{
                        al_play_sample(som_semDinheiro, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                    }

                }
            }else{
                if(noBotaoLabsAnterior){
                    al_draw_bitmap(botaoLabs2, 2, 279, 0);
                }
            }

            if (evento.mouse.x >= red_x*2 &&  //bot�o para comprar estufa
                evento.mouse.x <= red_x*21 &&
                evento.mouse.y <= red_y*327 &&
                evento.mouse.y >= red_y*307) {

                al_draw_bitmap(backgroundMonitor, 390, 274, 0);
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,273 , ALLEGRO_ALIGN_LEFT, "Pra plantar soja não");
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,285 , ALLEGRO_ALIGN_LEFT, "precisa TCC!!!");
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,297 , ALLEGRO_ALIGN_LEFT, "¯\\_(^_^)_/¯ ");
                al_draw_bitmap(botaoLabs, 2, 307, 0);
                noBotaoLabsAnterior = 1;

                if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                    custoEstufa = custo_calculo(custoBaseEstufa, qtdeEstufa, taxaCrescimentoEstufa);
                    if(custoEstufa<=dinheiro){
                        al_play_sample(som_botao, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                        qtdeEstufa += 1;
                        if(qtdeEstufa==1){
                            al_draw_bitmap(labEstufa, 6, 139, 0);
                        }
                        dinheiro -= custoEstufa;
                        prodEstufa = prod_calculo(prodBaseEstufa, qtdeEstufa, upgradeMultiplierEstufa);
                        al_draw_bitmap(backgroundLabs, 53, 307, 0);
                        al_draw_textf(fonteMenor, al_map_rgb(55, 68, 89), 53, 305, ALLEGRO_ALIGN_LEFT, "ESTUFA: %.0f", qtdeEstufa);
                        custoEstufa = custo_calculo(custoBaseEstufa, qtdeEstufa, taxaCrescimentoEstufa);
                        al_draw_textf(fonteMenor, al_map_rgb(55, 68, 89), 53, 315, ALLEGRO_ALIGN_LEFT, "custo: %.2f", custoEstufa);
                        al_draw_bitmap(backgroundMonitor, 390, 274, 0);
                        al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,273 , ALLEGRO_ALIGN_LEFT, "Pra plantar soja não");
                        al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,285 , ALLEGRO_ALIGN_LEFT, "precisa TCC!!!");
                        al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,297 , ALLEGRO_ALIGN_LEFT, "¯\\_(^_^)_/¯ ");
                    }
                    else{
                        al_play_sample(som_semDinheiro, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                    }
                }
            }else{
                if(noBotaoLabsAnterior){
                    al_draw_bitmap(botaoLabs2, 2, 307, 0);
                }
            }

            if (evento.mouse.x >= red_x*2 &&  //bot�o para comprar qu�mica
                evento.mouse.x <= red_x*21 &&
                evento.mouse.y <= red_y*355 &&
                evento.mouse.y >= red_y*335) {

                al_draw_bitmap(backgroundMonitor, 390, 274, 0);
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,273 , ALLEGRO_ALIGN_LEFT, "O que o álcool disse");
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,285 , ALLEGRO_ALIGN_LEFT, "para o outro álcool?");
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,297 , ALLEGRO_ALIGN_LEFT, "Etanóis!!! KKKKKKKKKKKKK");
                al_draw_bitmap(botaoLabs, 2, 335, 0);
                noBotaoLabsAnterior = 1;

                if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                    custoQuimica = custo_calculo(custoBaseQuimica, qtdeQuimica, taxaCrescimentoQuimica);
                    if(custoQuimica<=dinheiro){
                        al_play_sample(som_botao, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                        qtdeQuimica += 1;
                        if(qtdeQuimica==1){
                            al_draw_bitmap(labQuimica, 119, 41, 0);
                        }
                        dinheiro -= custoQuimica;
                        prodQuimica = prod_calculo(prodBaseQuimica, qtdeQuimica, upgradeMultiplierQuimica);
                        al_draw_bitmap(backgroundLabs, 53, 335, 0);
                        al_draw_textf(fonteMenor, al_map_rgb(55, 68, 89), 53, 333, ALLEGRO_ALIGN_LEFT, "QUIMICA: %.0f", qtdeQuimica);
                        custoQuimica = custo_calculo(custoBaseQuimica, qtdeQuimica, taxaCrescimentoQuimica);
                        al_draw_textf(fonteMenor, al_map_rgb(55, 68, 89), 53, 343, ALLEGRO_ALIGN_LEFT, "custo: %.2f", custoQuimica);
                        al_draw_bitmap(backgroundMonitor, 390, 274, 0);
                        al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,273 , ALLEGRO_ALIGN_LEFT, "O que o álcool disse");
                        al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,285 , ALLEGRO_ALIGN_LEFT, "para o outro álcool?");
                        al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,297 , ALLEGRO_ALIGN_LEFT, "Etanóis!!! KKKKKKKKKKKKK");
                    }else{
                        al_play_sample(som_semDinheiro, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                    }
                }
            }else{
                if(noBotaoLabsAnterior){
                    al_draw_bitmap(botaoLabs2, 2, 335, 0);
                }
            }

            if (evento.mouse.x >= red_x*165 &&  //bot�o para comprar f�sica
                evento.mouse.x <= red_x*184 &&
                evento.mouse.y <= red_y*299 &&
                evento.mouse.y >= red_y*279) {

                al_draw_bitmap(backgroundMonitor, 390, 274, 0);
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,273 , ALLEGRO_ALIGN_LEFT, "Hey camarada, Gagarin");
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,285 , ALLEGRO_ALIGN_LEFT, "precisa de mais espaço");
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,297 , ALLEGRO_ALIGN_LEFT, "para trazer o TANQUE!!");
                al_draw_bitmap(botaoLabs, 165, 279, 0);
                noBotaoLabsAnterior = 1;

                if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                    custoFisica = custo_calculo(custoBaseFisica, qtdeFisica, taxaCrescimentoFisica);
                    if(custoFisica<=dinheiro){
                        al_play_sample(som_botao, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                        qtdeFisica += 1;
                        if(qtdeFisica==1){
                            al_draw_bitmap(labFisica, 8, 41, 0);
                        }
                        dinheiro -= custoFisica;
                        prodFisica = prod_calculo(prodBaseFisica, qtdeFisica, upgradeMultiplierFisica);
                        al_draw_bitmap(backgroundLabs, 216, 279, 0);
                        al_draw_textf(fonteMenor, al_map_rgb(55, 68, 89), 216, 277, ALLEGRO_ALIGN_LEFT, "FISICA: %.0f", qtdeFisica);
                        custoFisica = custo_calculo(custoBaseFisica, qtdeFisica, taxaCrescimentoFisica);
                        al_draw_textf(fonteMenor, al_map_rgb(55, 68, 89), 216, 287, ALLEGRO_ALIGN_LEFT, "custo: %.2f", custoFisica);
                        al_draw_bitmap(backgroundMonitor, 390, 274, 0);
                        al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,273 , ALLEGRO_ALIGN_LEFT, "Hey camarada, Gagarin");
                        al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,285 , ALLEGRO_ALIGN_LEFT, "precisa de mais espaço");
                        al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,297 , ALLEGRO_ALIGN_LEFT, "para trazer o TANQUE!!");
                    }
                    else{
                        al_play_sample(som_semDinheiro, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                    }
                }
            }else{
                if(noBotaoLabsAnterior){
                    al_draw_bitmap(botaoLabs2, 165, 279, 0);
                }
            }

            if (evento.mouse.x >= red_x*165 &&  //bot�o para comprar rob�tica
                evento.mouse.x <= red_x*184 &&
                evento.mouse.y <= red_y*327 &&
                evento.mouse.y >= red_y*307) {

                al_draw_bitmap(backgroundMonitor, 390, 274, 0);
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,273 , ALLEGRO_ALIGN_LEFT, "Ya! queremos robôs!!!");
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,285 , ALLEGRO_ALIGN_LEFT, "estranho, pq aquele robô");
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,297 , ALLEGRO_ALIGN_LEFT, "está dizendo matar hum...");
                al_draw_bitmap(botaoLabs, 165, 307, 0);
                noBotaoLabsAnterior = 1;

                if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                    custoRobotica = custo_calculo(custoBaseRobotica, qtdeRobotica, taxaCrescimentoRobotica);
                    if(custoRobotica<=dinheiro){
                        al_play_sample(som_botao, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                        qtdeRobotica += 1;
                        if(qtdeRobotica==1){
                            al_draw_bitmap(labRobotica, 204, 148, 0);
                        }
                        dinheiro -= custoRobotica;
                        prodRobotica = prod_calculo(prodBaseRobotica, qtdeRobotica, upgradeMultiplierRobotica);
                        al_draw_bitmap(backgroundLabs, 216, 307, 0);
                        al_draw_textf(fonteMenor, al_map_rgb(55, 68, 89), 216, 305, ALLEGRO_ALIGN_LEFT, "ROBOTICA: %.0f", qtdeRobotica);
                        custoRobotica = custo_calculo(custoBaseRobotica, qtdeRobotica, taxaCrescimentoRobotica);
                        al_draw_textf(fonteMenor, al_map_rgb(55, 68, 89), 216, 315, ALLEGRO_ALIGN_LEFT, "custo: %.2f", custoRobotica);
                        al_draw_bitmap(backgroundMonitor, 390, 274, 0);
                        al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,273 , ALLEGRO_ALIGN_LEFT, "Ya! queremos robôs!!!");
                        al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,285 , ALLEGRO_ALIGN_LEFT, "estranho, pq aquele robô");
                        al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,297 , ALLEGRO_ALIGN_LEFT, "está dizendo matar hum...");
                    }else{
                        al_play_sample(som_semDinheiro, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                    }
                }
            }else{
                if(noBotaoLabsAnterior){
                    al_draw_bitmap(botaoLabs2, 165, 307, 0);
                }
            }

            if (evento.mouse.x >= red_x*165 &&  //bot�o para comprar nuclear
                evento.mouse.x <= red_x*184 &&
                evento.mouse.y <= red_y*355 &&
                evento.mouse.y >= red_y*335) {

                al_draw_bitmap(backgroundMonitor, 390, 274, 0);
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,273 , ALLEGRO_ALIGN_LEFT, "com mais espaço, po-");
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,285 , ALLEGRO_ALIGN_LEFT, "demos colocar um reator");
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,297 , ALLEGRO_ALIGN_LEFT, "o que pode dar errado?");
                al_draw_bitmap(botaoLabs, 165, 335, 0);
                noBotaoLabsAnterior = 1;

                if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                    custoNuclear = custo_calculo(custoBaseNuclear, qtdeNuclear, taxaCrescimentoNuclear);
                    if(custoNuclear<=dinheiro){
                        al_play_sample(som_botao, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                        qtdeNuclear += 1;
                        if(qtdeNuclear==1){
                            al_draw_bitmap(labNuclear, 349, 131, 0);
                        }
                        dinheiro -= custoNuclear;
                        prodNuclear = prod_calculo(prodBaseNuclear, qtdeNuclear, upgradeMultiplierNuclear);
                        al_draw_bitmap(backgroundLabs, 216, 335, 0);
                        al_draw_textf(fonteMenor, al_map_rgb(55, 68, 89), 216, 333, ALLEGRO_ALIGN_LEFT, "NUCLEAR: %.0f", qtdeNuclear);
                        custoNuclear = custo_calculo(custoBaseNuclear, qtdeNuclear, taxaCrescimentoNuclear);
                        al_draw_textf(fonteMenor, al_map_rgb(55, 68, 89), 216, 343, ALLEGRO_ALIGN_LEFT, "custo: %.2f", custoNuclear);
                        al_draw_bitmap(backgroundMonitor, 390, 274, 0);
                        al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,273 , ALLEGRO_ALIGN_LEFT, "com mais espaço, po-");
                        al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,285 , ALLEGRO_ALIGN_LEFT, "demos colocar um reator");
                        al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,297 , ALLEGRO_ALIGN_LEFT, "o que pode dar errado?");
                    }else{
                        al_play_sample(som_semDinheiro, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                    }
                }
            }else{
                if(noBotaoLabsAnterior){
                    al_draw_bitmap(botaoLabs2, 165, 335, 0);
                }
            }

            if (evento.mouse.x >= red_x*570 &&  //botão upgrade dormitorio (Laika)
                evento.mouse.x <= red_x*637 &&
                evento.mouse.y <= red_y*75 &&
                evento.mouse.y >= red_y*50) {

                al_draw_bitmap(botaoUpgradeDormitorio, 569, 49, 0);
                noBotaoAnteriorUD = 1;
                al_draw_bitmap(backgroundMonitor, 390, 274, 0);
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,273 , ALLEGRO_ALIGN_LEFT, "Olha, aquela");
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,285 , ALLEGRO_ALIGN_LEFT, "cadela não é");
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,297 , ALLEGRO_ALIGN_LEFT, "a Laika?");

                if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                    if(!upgradeDormitorio){
                        if(custoUpgradeDormitorio<=dinheiro){
                            if(qtdeDormitorio>0){
                                al_show_native_message_box(janela, "LAIKA Upgrade!","Você comprou o Upgrade da LAIKA!","Com sucesso resgatamos a cadela LAIKA, agora temos uma amiguinha, depois de flutuar no espaço ela ficou enorme!",NULL,ALLEGRO_MESSAGEBOX_WARN);
                                al_draw_bitmap(labDormitorioUpgrade, 280, 36, 0);
                                al_play_sample(som_botao, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                                dinheiro -= custoUpgradeDormitorio;
                                upgradeMultiplierDormitorio = 2;
                                prodDormitorio = prod_calculo(prodBaseDormitorio, qtdeDormitorio, upgradeMultiplierDormitorio);
                                al_draw_bitmap(led, 555, 50, 0);
                                upgradeDormitorio = 1;
                            }
                        }else{
                        al_play_sample(som_semDinheiro, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                        }
                    }
                }
            }else{
                if(noBotaoAnteriorUD){
                    al_draw_bitmap(botaoUpgradeDormitorio2, 569, 49, 0);
                    noBotaoAnteriorUD=0;
                }
            }

            if (evento.mouse.x >= red_x*570 &&  //botão upgrade estufa (Espantalho)
                evento.mouse.x <= red_x*637 &&
                evento.mouse.y <= red_y*102 &&
                evento.mouse.y >= red_y*77) {

                al_draw_bitmap(botaoUpgradeEstufa, 569, 76, 0);
                noBotaoAnteriorUE = 1;
                al_draw_bitmap(backgroundMonitor, 390, 274, 0);
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,273 , ALLEGRO_ALIGN_LEFT, "Acho que o Trump");
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,285 , ALLEGRO_ALIGN_LEFT, "daria um bom espantalho");
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,297 , ALLEGRO_ALIGN_LEFT, "Xô corvos espaciais");

                if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                    if(!upgradeEstufa){
                        if(custoUpgradeEstufa<=dinheiro){
                            if((qtdeEstufa>0)&&(upgradeDormitorio==1)){
                                al_show_native_message_box(janela, "ESPANTALHO Upgrade!","Você comprou o Upgrade do ESPANTALHO!","Nossas plantações de milho estavam sendo atacadas por corvos espaciais, contratamos um cara parecido com o TRUMP para assustar os pássaros!",NULL,ALLEGRO_MESSAGEBOX_WARN);
                                al_draw_bitmap(labEstufaUpgrade, 6, 139, 0);
                                al_play_sample(som_botao, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                                dinheiro -= custoUpgradeEstufa;
                                upgradeMultiplierEstufa = 2;
                                prodEstufa = prod_calculo(prodBaseEstufa, qtdeEstufa, upgradeMultiplierEstufa);
                                al_draw_bitmap(led, 555, 77, 0);
                                upgradeEstufa = 1;
                            }
                        }else{
                        al_play_sample(som_semDinheiro, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                        }
                    }
                }
            }else{
                if(noBotaoAnteriorUE){
                    al_draw_bitmap(botaoUpgradeEstufa2, 569, 76, 0);
                    noBotaoAnteriorUE=0;
                }
            }

            if (evento.mouse.x >= red_x*570 &&  //botão upgrade quimica (Vodka)
                evento.mouse.x <= red_x*637 &&
                evento.mouse.y <= red_y*129 &&
                evento.mouse.y >= red_y*104) {

                al_draw_bitmap(botaoUpgradeQuimica, 569, 103, 0);
                noBotaoAnteriorUQ = 1;
                al_draw_bitmap(backgroundMonitor, 390, 274, 0);
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,273 , ALLEGRO_ALIGN_LEFT, "Agora sim podemos");
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,285 , ALLEGRO_ALIGN_LEFT, "fabricar VODKA para");
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,297 , ALLEGRO_ALIGN_LEFT, "todos cosmonautas!!!");

                if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                    if(!upgradeQuimica){
                        if(custoUpgradeQuimica<=dinheiro){
                            if((qtdeQuimica>0)&&(upgradeDormitorio==1)&&(upgradeEstufa==1)){
                                al_show_native_message_box(janela, "VODKA Upgrade!","Você comprou o Upgrade da VODKA!","O laboratório de química já tinha suas utilidades, agora ele produz vodka em massa para a estação!",NULL,ALLEGRO_MESSAGEBOX_WARN);
                                al_draw_bitmap(labQuimicaUpgrade, 119, 41, 0);
                                al_play_sample(som_botao, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                                dinheiro -= custoUpgradeQuimica;
                                upgradeMultiplierQuimica = 2;
                                prodQuimica = prod_calculo(prodBaseQuimica, qtdeQuimica, upgradeMultiplierQuimica);
                                al_draw_bitmap(led, 555, 104, 0);
                                upgradeQuimica = 1;
                            }
                        }else{
                        al_play_sample(som_semDinheiro, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                        }
                    }
                }
            }else{
                if(noBotaoAnteriorUQ){
                    al_draw_bitmap(botaoUpgradeQuimica2, 569, 103, 0);
                    noBotaoAnteriorUQ=0;
                }
            }

            if (evento.mouse.x >= red_x*570 &&  //botão upgrade fisica (estúdio)
                evento.mouse.x <= red_x*637 &&
                evento.mouse.y <= red_y*156 &&
                evento.mouse.y >= red_y*131) {

                al_draw_bitmap(botaoUpgradeFisica, 569, 130, 0);
                noBotaoAnteriorUF = 1;
                al_draw_bitmap(backgroundMonitor, 390, 274, 0);
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,273 , ALLEGRO_ALIGN_LEFT, "Agora iremos para a");
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,285 , ALLEGRO_ALIGN_LEFT, "lua... assim como os");
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,297 , ALLEGRO_ALIGN_LEFT, "americanos foram... ");

                if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                    if(!upgradeFisica){
                        if(custoUpgradeFisica<=dinheiro){
                            if((qtdeFisica>0)&&(upgradeDormitorio==1)&&(upgradeEstufa==1)&&(upgradeQuimica==1)){
                                al_show_native_message_box(janela, "ESTÚDIO Upgrade!","Você comprou o Upgrade do Estúdio!","Transformamos o laboratório de física num estúdio, para gravarmos a ida do soviético a lua!",NULL,ALLEGRO_MESSAGEBOX_WARN);
                                al_draw_bitmap(labFisicaUpgrade, 8, 41, 0);
                                al_play_sample(som_botao, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                                dinheiro -= custoUpgradeFisica;
                                upgradeMultiplierFisica = 2;
                                prodFisica = prod_calculo(prodBaseFisica, qtdeFisica, upgradeMultiplierFisica);
                                al_draw_bitmap(led, 555, 131, 0);
                                upgradeFisica = 1;
                            }
                        }else{
                        al_play_sample(som_semDinheiro, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                        }
                    }
                }
            }else{
                if(noBotaoAnteriorUF){
                    al_draw_bitmap(botaoUpgradeFisica2, 569, 130, 0);
                    noBotaoAnteriorUF = 0;
                }
            }

            if (evento.mouse.x >= red_x*570 &&  //botão upgrade robotica (zanetti)
                evento.mouse.x <= red_x*637 &&
                evento.mouse.y <= red_y*183 &&
                evento.mouse.y >= red_y*158) {

                al_draw_bitmap(botaoUpgradeRobotica, 569, 157, 0);
                noBotaoAnteriorUR = 1;
                al_draw_bitmap(backgroundMonitor, 390, 274, 0);
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,273 , ALLEGRO_ALIGN_LEFT, "Da URSS para a");
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,285 , ALLEGRO_ALIGN_LEFT, "TERRA: precisamos ");
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,297 , ALLEGRO_ALIGN_LEFT, "do professor Zanetti");

                if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                    if(!upgradeRobotica){
                        if(custoUpgradeRobotica<=dinheiro){
                            if((qtdeRobotica>0)&&(upgradeDormitorio==1)&&(upgradeEstufa==1)&&(upgradeFisica==1)&&(upgradeQuimica==1)){
                                al_show_native_message_box(janela, "ZANETTI Upgrade!","Você comprou o Upgrade do Zanetti!","A URSS Convidou o professor Zanetti para participar do núcleo de robótica da estação, agora a estação tem o selo Zanetti de qualidade!",NULL,ALLEGRO_MESSAGEBOX_WARN);
                                al_draw_bitmap(labRoboticaUpgrade, 204, 148, 0);
                                al_play_sample(som_botao, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                                dinheiro -= custoUpgradeRobotica;
                                upgradeMultiplierRobotica = 2;
                                prodRobotica = prod_calculo(prodBaseRobotica, qtdeRobotica, upgradeMultiplierRobotica);
                                al_draw_bitmap(led, 555, 158, 0);
                                upgradeRobotica = 1;
                            }
                        }else{
                        al_play_sample(som_semDinheiro, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                        }
                    }
                }
            }else{
                if(noBotaoAnteriorUR){
                    al_draw_bitmap(botaoUpgradeRobotica2, 569, 157, 0);
                    noBotaoAnteriorUR=0;
                }
            }

            if (evento.mouse.x >= red_x*570 &&  //botão upgrade nuclear ()
                evento.mouse.x <= red_x*637 &&
                evento.mouse.y <= red_y*210 &&
                evento.mouse.y >= red_y*185) {

                al_draw_bitmap(botaoUpgradeNuclear, 569, 184, 0);
                noBotaoAnteriorUN = 1;
                al_draw_bitmap(backgroundMonitor, 390, 274, 0);
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,273 , ALLEGRO_ALIGN_LEFT, "A KGB quer desenvolver");
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,285 , ALLEGRO_ALIGN_LEFT, "armas AK-47 com pro-");
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,297 , ALLEGRO_ALIGN_LEFT, "jéteis radioativos!");

                if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                    if(!upgradeNuclear){
                        if(custoUpgradeNuclear<=dinheiro){
                            if((qtdeNuclear>0)&&(upgradeDormitorio==1)&&(upgradeEstufa==1)&&(upgradeFisica==1)&&(upgradeQuimica==1)&&(upgradeRobotica==1)){
                                al_show_native_message_box(janela, "KGB Upgrade!","Você comprou o Upgrade da KGB!","Agora a KGB controla a produção de urânio espacial, e adicionamos uma estátua do glorioso Putin...",NULL,ALLEGRO_MESSAGEBOX_WARN);
                                al_draw_bitmap(labNuclearUpgrade, 349, 131, 0);
                                al_play_sample(som_botao, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                                dinheiro -= custoUpgradeNuclear;
                                upgradeMultiplierNuclear = 2;
                                prodNuclear = prod_calculo(prodBaseNuclear, qtdeNuclear, upgradeMultiplierNuclear);
                                al_draw_bitmap(led, 555, 185, 0);
                                upgradeNuclear = 1;
                            }
                        }else{
                        al_play_sample(som_semDinheiro, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                        }
                    }
                }
            }else{
                if(noBotaoAnteriorUN){
                    al_draw_bitmap(botaoUpgradeNuclear2, 569, 184, 0);
                    noBotaoAnteriorUN=0;
                }
            }

            if (evento.mouse.x >= red_x*570 &&  //botão upgrade final (O final)
                evento.mouse.x <= red_x*637 &&
                evento.mouse.y <= red_y*237 &&
                evento.mouse.y >= red_y*212) {

                al_draw_bitmap(botaoUpgradeFinal, 569, 211, 0);
                noBotaoAnteriorUO = 1;
                al_draw_bitmap(backgroundMonitor, 390, 274, 0);
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,273 , ALLEGRO_ALIGN_LEFT, "O que? Quem são");
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,285 , ALLEGRO_ALIGN_LEFT, "o Enzo Filippo");
                al_draw_textf(fonteMenor, al_map_rgb(85, 255, 0), 393,297 , ALLEGRO_ALIGN_LEFT, "e Vitor Mateus?");

                if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                    if(!upgradeFinal){
                        if(custoUpgradeFinal<=dinheiro){
                            if((upgradeNuclear==1)&&(upgradeDormitorio==1)&&(upgradeEstufa==1)&&(upgradeFisica==1)&&(upgradeQuimica==1)&&(upgradeRobotica==1)){
                                int iniciarNovoJogo = al_show_native_message_box(
                                    janela,
                                    "URSS - Ultimate Restless Space Station",
                                    "Previet Camarada",
                                    "Ao que tudo indica, você superou todos os desafios para criar uma estação espacial digna dos czares. Claro, os czares estão ultrapassados, mas sinto em dizer-lhe que você também está!"
                                    " Nossos cientistas descobriram recentemente que estamos vivendo numa simulação computacional, que eles costumam chamar de jogo, parece uma invenção capitalista. Esta simulação foi"
                                    " criada por Enzo Filippo e Vitor Mateus para ganhar algum tipo de promoção com um tal de Zanetti, eles são da turma T6 do curso de engenharia aeroespacial, pelo menos alguma coisa "
                                    " é espacial de verdade. Nossas vidas tem sido uma mentira, nos escravizaram por entretenimento, em troca nos davam vodka! Na verdade, até que gosto da vodka, deseja continuar jogando?",
                                    NULL,
                                    ALLEGRO_MESSAGEBOX_YES_NO
                                    );
                                if (!iniciarNovoJogo){
                                    al_play_sample(som_botao, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                                    saveGame(0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0);
                                    al_destroy_sample(som_botao);
                                    al_destroy_audio_stream(musica);
                                    al_destroy_timer(timer);
                                    al_destroy_font(fonte);
                                    al_destroy_display(janela);
                                    al_destroy_event_queue(filaEventos);
                                    al_destroy_event_queue(filaEventosTimer);
                                    inicializar();
                                    interface_game();
                                }else{
                                    dinheiro -= custoUpgradeFinal;
                                    al_draw_bitmap(led, 555, 212, 0);
                                    upgradeFinal=1;
                                    upgradeMultiplierDormitorio = 3;
                                    upgradeMultiplierEstufa = 3;
                                    upgradeMultiplierQuimica = 3;
                                    upgradeMultiplierFisica = 3;
                                    upgradeMultiplierRobotica = 3;
                                    upgradeMultiplierNuclear = 3;
                                }

                            }
                        }else{
                        al_play_sample(som_semDinheiro, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                        }
                    }
                }
            }else{
                if(noBotaoAnteriorUO){
                    al_draw_bitmap(botaoUpgradeFinal2, 569, 211, 0);
                    noBotaoAnteriorUO=0;
                }
            }

        }
        while(!al_is_event_queue_empty(filaEventosTimer)){ //atualizar dinheiro na tela
            ALLEGRO_EVENT evento;
            al_wait_for_event(filaEventosTimer, &evento);

            dinheiroPorSegundo = prodDormitorio + prodEstufa + prodQuimica + prodFisica + prodRobotica + prodNuclear;
            incrementoPorFrame = dinheiroPorSegundo/FPS;
            dinheiro += incrementoPorFrame;

            al_draw_bitmap(backgroundDinheiroPorSegundo, 88, 6, 0);
            al_draw_textf(fonte, al_map_rgb(153, 229, 80), 256, 0, ALLEGRO_ALIGN_RIGHT, "%.2f", dinheiroPorSegundo);
            al_draw_bitmap(backgroundDinheiro, 263, 6, 0);
            al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA_TELA - 38, 0, ALLEGRO_ALIGN_RIGHT, "%.2f", dinheiro);

        }
        al_flip_display();
    }

    al_destroy_sample(som_botao);
    al_destroy_audio_stream(musica);
    al_destroy_timer(timer);
    al_destroy_font(fonte);
    al_destroy_display(janela);
    al_destroy_event_queue(filaEventos);
    al_destroy_event_queue(filaEventosTimer);

    return 0;
}
