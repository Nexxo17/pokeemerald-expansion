LittlerootTown_MapScripts::
# 2 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_PUEBLO_MATIZ_INICIO, 0, script_inicio_matiz
	.2byte 0


script_inicio_matiz::
# 8 "data/maps/LittlerootTown/scripts.pory"
	lock
# 10 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, rata_movement
# 11 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_PUEBLO_MATIZ_INICIO, 1
# 12 "data/maps/LittlerootTown/scripts.pory"
	delay 16
# 13 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8000, MUGSHOT_MINI_CHANO
# 14 "data/maps/LittlerootTown/scripts.pory"
	callnative DrawMugshot2
# 15 "data/maps/LittlerootTown/scripts.pory"
	msgbox chano01
# 16 "data/maps/LittlerootTown/scripts.pory"
	callnative ClearMugshot
# 17 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 18 "data/maps/LittlerootTown/scripts.pory"
	delay 24
# 19 "data/maps/LittlerootTown/scripts.pory"
	playmoncry SPECIES_RATTATA, CRY_MODE_NORMAL
# 20 "data/maps/LittlerootTown/scripts.pory"
	msgbox script_inicio_matiz_Text_0
# 21 "data/maps/LittlerootTown/scripts.pory"
	delay 24
# 22 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 23 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8000, MUGSHOT_MINI_CHANO
# 24 "data/maps/LittlerootTown/scripts.pory"
	callnative DrawMugshot2
# 25 "data/maps/LittlerootTown/scripts.pory"
	msgbox chano02
# 26 "data/maps/LittlerootTown/scripts.pory"
	callnative ClearMugshot
# 27 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 28 "data/maps/LittlerootTown/scripts.pory"
	fadescreen 1
# 29 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_RATTATA
# 30 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 1, MAP_LITTLEROOT_TOWN
# 31 "data/maps/LittlerootTown/scripts.pory"
	delay 16
# 32 "data/maps/LittlerootTown/scripts.pory"
	fadescreen 0
	return


# 35 "data/maps/LittlerootTown/scripts.pory"
rata_movement:
# 36 "data/maps/LittlerootTown/scripts.pory"
	face_up
	step_end

sign_msg::
# 48 "data/maps/LittlerootTown/scripts.pory"
	msgbox msg_sign_17, MSGBOX_SIGN
	return


fat_man::
# 56 "data/maps/LittlerootTown/scripts.pory"
	lock
# 57 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 58 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_TEMP_2, fat_man_2
# 62 "data/maps/LittlerootTown/scripts.pory"
	msgbox fat_man_Text_1
fat_man_1:
# 64 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 65 "data/maps/LittlerootTown/scripts.pory"
	release
	return

fat_man_2:
# 59 "data/maps/LittlerootTown/scripts.pory"
	msgbox fat_man_Text_0
	goto fat_man_1


anciano_scr::
# 69 "data/maps/LittlerootTown/scripts.pory"
	lock
# 70 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 71 "data/maps/LittlerootTown/scripts.pory"
	msgbox anciano_scr_Text_0
# 72 "data/maps/LittlerootTown/scripts.pory"
	closemessage
	return


scr_boy_paper::
# 76 "data/maps/LittlerootTown/scripts.pory"
	lock
# 77 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 78 "data/maps/LittlerootTown/scripts.pory"
	msgbox boy_paper_txt, MSGBOX_YESNO
# 79 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq scr_boy_paper_1
# 83 "data/maps/LittlerootTown/scripts.pory"
	msgbox scr_boy_paper_Text_0
	return

scr_boy_paper_1:
# 80 "data/maps/LittlerootTown/scripts.pory"
	goto scr_rock_paper_game
	return


scr_rock_paper_game::
# 94 "data/maps/LittlerootTown/scripts.pory"
	lock
# 95 "data/maps/LittlerootTown/scripts.pory"
	msgbox msg_rsp_game, MSGBOX_DEFAULT
# 96 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 97 "data/maps/LittlerootTown/scripts.pory"
	callnative HandsGameDraw
# 98 "data/maps/LittlerootTown/scripts.pory"
	multichoicegrid 6, 16, MULTI_TAG_ROCK_PAPER_SCISORS, 3, 1
# 99 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 100 "data/maps/LittlerootTown/scripts.pory"
	case 0, scr_rock_paper_game_3
# 111 "data/maps/LittlerootTown/scripts.pory"
	case 1, scr_rock_paper_game_4
# 122 "data/maps/LittlerootTown/scripts.pory"
	case 2, scr_rock_paper_game_5
scr_rock_paper_game_1:
# 134 "data/maps/LittlerootTown/scripts.pory"
	msgbox boy_play_again, MSGBOX_YESNO
# 135 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq scr_rock_paper_game_7
# 139 "data/maps/LittlerootTown/scripts.pory"
	msgbox scr_boy_paper_Text_0
scr_rock_paper_game_6:
# 141 "data/maps/LittlerootTown/scripts.pory"
	release
	return

scr_rock_paper_game_3:
# 101 "data/maps/LittlerootTown/scripts.pory"
	callnative HandsGameClean
# 102 "data/maps/LittlerootTown/scripts.pory"
	random 3
# 103 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 104 "data/maps/LittlerootTown/scripts.pory"
	case 0, scr_rock_paper_game_11
# 106 "data/maps/LittlerootTown/scripts.pory"
	case 1, scr_rock_paper_game_12
# 108 "data/maps/LittlerootTown/scripts.pory"
	case 2, scr_rock_paper_game_13
	goto scr_rock_paper_game_1

scr_rock_paper_game_4:
# 112 "data/maps/LittlerootTown/scripts.pory"
	callnative HandsGameClean
# 113 "data/maps/LittlerootTown/scripts.pory"
	random 3
# 114 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 115 "data/maps/LittlerootTown/scripts.pory"
	case 0, scr_rock_paper_game_15
# 117 "data/maps/LittlerootTown/scripts.pory"
	case 1, scr_rock_paper_game_16
# 119 "data/maps/LittlerootTown/scripts.pory"
	case 2, scr_rock_paper_game_17
	goto scr_rock_paper_game_1

scr_rock_paper_game_5:
# 123 "data/maps/LittlerootTown/scripts.pory"
	callnative HandsGameClean
# 124 "data/maps/LittlerootTown/scripts.pory"
	random 3
# 125 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 126 "data/maps/LittlerootTown/scripts.pory"
	case 0, scr_rock_paper_game_19
# 128 "data/maps/LittlerootTown/scripts.pory"
	case 1, scr_rock_paper_game_20
# 130 "data/maps/LittlerootTown/scripts.pory"
	case 2, scr_rock_paper_game_21
	goto scr_rock_paper_game_1

scr_rock_paper_game_7:
# 136 "data/maps/LittlerootTown/scripts.pory"
	goto scr_rock_paper_game
	goto scr_rock_paper_game_6

scr_rock_paper_game_11:
# 105 "data/maps/LittlerootTown/scripts.pory"
	msgbox msg_draw
	goto scr_rock_paper_game_1

scr_rock_paper_game_12:
# 107 "data/maps/LittlerootTown/scripts.pory"
	goto scr_win
	goto scr_rock_paper_game_1

scr_rock_paper_game_13:
# 109 "data/maps/LittlerootTown/scripts.pory"
	msgbox msg_lose
	goto scr_rock_paper_game_1

scr_rock_paper_game_15:
# 116 "data/maps/LittlerootTown/scripts.pory"
	msgbox msg_lose
	goto scr_rock_paper_game_1

scr_rock_paper_game_16:
# 118 "data/maps/LittlerootTown/scripts.pory"
	msgbox msg_draw
	goto scr_rock_paper_game_1

scr_rock_paper_game_17:
# 120 "data/maps/LittlerootTown/scripts.pory"
	goto scr_win
	goto scr_rock_paper_game_1

scr_rock_paper_game_19:
# 127 "data/maps/LittlerootTown/scripts.pory"
	goto scr_win
	goto scr_rock_paper_game_1

scr_rock_paper_game_20:
# 129 "data/maps/LittlerootTown/scripts.pory"
	msgbox msg_lose
	goto scr_rock_paper_game_1

scr_rock_paper_game_21:
# 131 "data/maps/LittlerootTown/scripts.pory"
	msgbox msg_draw
	goto scr_rock_paper_game_1


scr_win::
# 149 "data/maps/LittlerootTown/scripts.pory"
	msgbox msg_win
# 150 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 151 "data/maps/LittlerootTown/scripts.pory"
	applymovement 5, mov_boy01
# 152 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 5
# 153 "data/maps/LittlerootTown/scripts.pory"
	delay 40
	return


# 158 "data/maps/LittlerootTown/scripts.pory"
mov_boy01:
# 159 "data/maps/LittlerootTown/scripts.pory"
	emote_heart
	step_end

girl_scr::
# 179 "data/maps/LittlerootTown/scripts.pory"
	lock
# 180 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 181 "data/maps/LittlerootTown/scripts.pory"
	msgbox girl_scr_Text_0
# 182 "data/maps/LittlerootTown/scripts.pory"
	release
	return


script_inicio_matiz_Text_0:
# 20 "data/maps/LittlerootTown/scripts.pory"
	.string "¡RAAAATAAATTAAA!$"

fat_man_Text_0:
# 59 "data/maps/LittlerootTown/scripts.pory"
	.string "Oh, era mi botella de agua, bueno,\n"
	.string "puedes quedartela, de todas formas ya\l"
	.string "no tengo sed.$"

fat_man_Text_1:
# 62 "data/maps/LittlerootTown/scripts.pory"
	.string "Mira, que roca mas curiosa... Bueno, en\n"
	.string "realidad es como las demas, pero parece\l"
	.string "tener algo debajo, puedes ver que es?$"

anciano_scr_Text_0:
# 71 "data/maps/LittlerootTown/scripts.pory"
	.string "Estos crios parecen disfrutar\n"
	.string "molestarme a la hora de la siesta...$"

scr_boy_paper_Text_0:
# 83 "data/maps/LittlerootTown/scripts.pory"
	.string "Esta bien, tu te lo pierdes...$"

girl_scr_Text_0:
# 181 "data/maps/LittlerootTown/scripts.pory"
	.string "Mi hermano no sabe que siempre lo dejo\n"
	.string "ganar en piedra, papel o tijeras porque\l"
	.string "le cuenta a nuestra madre y me regaña.$"

chano01::
# 39 "data/maps/LittlerootTown/scripts.pory"
	.string "¡Vaya calor que hace... el día\nestá precioso, ¿no crees,\lRattata?$"

chano02::
# 43 "data/maps/LittlerootTown/scripts.pory"
	.string "¡Sin duda! Bien... debemos\naprovechar nuestro tiempo.\pNo quiero llegar muy tarde a\ncasa.\pVamos directo a la Ruta 17;\nseguro encontraremos algún\lentrenador con ganas de\lenfrentarnos.$"

msg_sign_17::
# 51 "data/maps/LittlerootTown/scripts.pory"
	.string "Ruta 17\n"
	.string "-->$"

boy_paper_txt::
# 89 "data/maps/LittlerootTown/scripts.pory"
	.string "Juego piedras papel y tijeras con mi\n"
	.string "hermana, soy el mejor de todos los\l"
	.string "tiempos en este juego, gano siempre.\p"
	.string "Quieres hechar una partida?$"

boy_play_again::
# 144 "data/maps/LittlerootTown/scripts.pory"
	.string "¿Te apetece echar otra vez?$"

msg_lose::
# 162 "data/maps/LittlerootTown/scripts.pory"
	.string "Ja, te lo dije, soy el mejor en este\n"
	.string "juego, sabía que ganaría.$"

msg_win::
# 166 "data/maps/LittlerootTown/scripts.pory"
	.string "Eres un maldito tramposo.$"

msg_draw::
# 170 "data/maps/LittlerootTown/scripts.pory"
	.string "Siéntete orgulloso de haber empatado;\n"
	.string "si hubiera querido, ya sería el ganador.$"

msg_rsp_game::
# 174 "data/maps/LittlerootTown/scripts.pory"
	.string "Bien, que empiece el juego...\p"
	.string "3...\p"
	.string "2...\p"
	.string "1...$"
