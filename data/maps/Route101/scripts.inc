Route101_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Route101_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_0, 1, scr_meteor
	.2byte 0


scr_trainer_boy::
	lock
	delay 16
	compare VAR_TEMP_2, 1
	goto_if_ge scr_trainer_boy_2
scr_trainer_boy_1:
	setvar VAR_TEMP_2, 1
	applymovement OBJ_EVENT_ID_PLAYER, mov_player_01
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 32
	setvar VAR_0x8000, MUGSHOT_MINI_CHANO
	callnative DrawMugshot2
	msgbox msg_chano_trainer_0
	callnative ClearMugshot
	closemessage
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, mov_player_02
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 16
	setvar VAR_0x8000, MUGSHOT_MINI_CHANO
	callnative DrawMugshot2
	msgbox msg_chano_trainer_1
	callnative ClearMugshot
	closemessage
	release
	return

scr_trainer_boy_2:
	goto scr_trainer_noexit
	goto scr_trainer_boy_1


scr_trainer_noexit::
	applymovement OBJ_EVENT_ID_PLAYER, player_mov_noexit
	return


player_mov_noexit:
	walk_right
	step_end

mov_player_01:
	emote_exclamation_mark
	step_end

mov_player_02:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

boy_trainer::
	lock
	faceplayer
	clearflag FLAG_PIDGEY
	setvar VAR_TEMP_0, 2
	setvar VAR_0x8000, MUGSHOT_MINI_CHANO
	callnative DrawMugshot2
	msgbox msg_chano_trainer_2
	callnative ClearMugshot
	closemessage
	msgbox boy_trainer_Text_0
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_SAWYER_1, 1, msg_boy_0, msg_boy_1, scr_meteor
	msgbox boy_trainer_Text_1
	return


scr_meteor::
	lock
	setvar VAR_0x8000, MUGSHOT_MINI_CHANO
	callnative DrawMugshot2
	msgbox msgchano_2
	callnative ClearMugshot
	closemessage
	delay 32
	applymovement OBJ_EVENT_ID_PLAYER, mov_chano_0
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 32
	setvar VAR_0x8000, MUGSHOT_MINI_CHANO
	callnative DrawMugshot
	msgbox msg_chano_pidgey_0
	callnative ClearMugshot
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, mov_chano_1
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 16
	setvar VAR_0x8000, MUGSHOT_MINI_CHANO
	callnative DrawMugshot
	msgbox msg_chano_pidgey_1
	callnative ClearMugshot
	closemessage
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, mov_pidgey
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 60
	setflag FLAG_SPAWN_INVISIBLE
	setvar VAR_TEMP_0, 2
	warp MAP_OLDALE_TOWN_HOUSE1, 7, 4
	return


mov_chano_0:
	delay_16
	face_left
	delay_16
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	step_end

mov_chano_1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

mov_pidgey:
	emote_exclamation_mark
	delay_16
	face_up
	step_end

boy_trainer_Text_0:
	.string "Bien, acepto tu propuesta.$"

boy_trainer_Text_1:
	.string "Hola$"

msg_chano_trainer_0::
	.string "Oh, un entrenador, que suerte he\n"
	.string "tenido, genial, ire a preguntarle\l"
	.string "si quiere un combate.$"

msg_chano_trainer_1::
	.string "Bien, veremos que dice, rattata\n"
	.string "tiene ganas de un combate\l"
	.string "tambien, esto sea emocionante.$"

msg_chano_trainer_2::
	.string "Oye, te apetece un combate?$"

msg_boy_0::
	.string "No pienso perder$"

msg_boy_1::
	.string "Y perdi de todas formas$"

msg_chano_pidgey_0::
	.string "Increible, un pigey salvaje,\n"
	.string "tengo que aprovecharlo$"

msg_chano_pidgey_1::
	.string "Te ves fuerte, no quieres acaso\n"
	.string "unirte a mi equipo?$"

msgchano_2::
	.string "Buen comba...$"
