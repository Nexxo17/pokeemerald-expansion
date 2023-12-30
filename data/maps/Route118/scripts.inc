# 1 "data/maps/Route118/scripts.pory"

# 2 "data/maps/Route118/scripts.pory"
.set LOCALID_STEVEN, 19
# 3 "data/maps/Route118/scripts.pory"

# 4 "data/maps/Route118/scripts.pory"
Route118_MapScripts::
# 5 "data/maps/Route118/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route118_OnTransition
# 6 "data/maps/Route118/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route118_OnLoad
# 7 "data/maps/Route118/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route118_OnFrame
# 8 "data/maps/Route118/scripts.pory"
	.byte 0
# 9 "data/maps/Route118/scripts.pory"

# 10 "data/maps/Route118/scripts.pory"
Route118_OnTransition:
# 11 "data/maps/Route118/scripts.pory"
	call GabbyAndTy_EventScript_UpdateLocation
# 12 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
# 13 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_EAST, AbnormalWeather_StartGroudonWeather
# 14 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_WEST, AbnormalWeather_StartGroudonWeather
# 15 "data/maps/Route118/scripts.pory"
	end
# 16 "data/maps/Route118/scripts.pory"

# 17 "data/maps/Route118/scripts.pory"
Route118_OnLoad:
# 18 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_EAST, AbnormalWeather_EventScript_PlaceTilesRoute118East
# 19 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_WEST, AbnormalWeather_EventScript_PlaceTilesRoute118West
# 20 "data/maps/Route118/scripts.pory"
	end
# 21 "data/maps/Route118/scripts.pory"

# 22 "data/maps/Route118/scripts.pory"
Route118_OnFrame:
# 23 "data/maps/Route118/scripts.pory"
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
# 24 "data/maps/Route118/scripts.pory"
	.2byte 0
# 25 "data/maps/Route118/scripts.pory"

# 26 "data/maps/Route118/scripts.pory"
Route118_EventScript_GoodRodFisherman::
# 27 "data/maps/Route118/scripts.pory"
	lock
# 28 "data/maps/Route118/scripts.pory"
	faceplayer
# 29 "data/maps/Route118/scripts.pory"
	goto_if_set FLAG_RECEIVED_GOOD_ROD, Route118_EventScript_ReceivedGoodRod
# 30 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_YouAgreeGoodRodIsGood, MSGBOX_YESNO
# 31 "data/maps/Route118/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route118_EventScript_ReceiveGoodRod
# 32 "data/maps/Route118/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route118_EventScript_DeclineGoodRod
# 33 "data/maps/Route118/scripts.pory"
	end
# 34 "data/maps/Route118/scripts.pory"

# 35 "data/maps/Route118/scripts.pory"
Route118_EventScript_ReceiveGoodRod::
# 36 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_IdenticalMindsTakeThis, MSGBOX_DEFAULT
# 37 "data/maps/Route118/scripts.pory"
	giveitem ITEM_GOOD_ROD
# 38 "data/maps/Route118/scripts.pory"
	setflag FLAG_RECEIVED_GOOD_ROD
# 39 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_TryYourLuckFishing, MSGBOX_DEFAULT
# 40 "data/maps/Route118/scripts.pory"
	release
# 41 "data/maps/Route118/scripts.pory"
	end
# 42 "data/maps/Route118/scripts.pory"

# 43 "data/maps/Route118/scripts.pory"
Route118_EventScript_DeclineGoodRod::
# 44 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_DontYouLikeToFish, MSGBOX_DEFAULT
# 45 "data/maps/Route118/scripts.pory"
	release
# 46 "data/maps/Route118/scripts.pory"
	end
# 47 "data/maps/Route118/scripts.pory"

# 48 "data/maps/Route118/scripts.pory"
Route118_EventScript_ReceivedGoodRod::
# 49 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_TryCatchingMonWithGoodRod, MSGBOX_DEFAULT
# 50 "data/maps/Route118/scripts.pory"
	release
# 51 "data/maps/Route118/scripts.pory"
	end
# 52 "data/maps/Route118/scripts.pory"

# 53 "data/maps/Route118/scripts.pory"
Route118_EventScript_Girl::
# 54 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_CanCrossRiversWithSurf, MSGBOX_NPC
# 55 "data/maps/Route118/scripts.pory"
	end
# 56 "data/maps/Route118/scripts.pory"

# 57 "data/maps/Route118/scripts.pory"
Route118_EventScript_RouteSignMauville::
# 58 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_RouteSignMauville, MSGBOX_SIGN
# 59 "data/maps/Route118/scripts.pory"
	end
# 60 "data/maps/Route118/scripts.pory"

# 61 "data/maps/Route118/scripts.pory"
Route118_EventScript_RouteSign119::
# 62 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_RouteSign119, MSGBOX_SIGN
# 63 "data/maps/Route118/scripts.pory"
	end
# 64 "data/maps/Route118/scripts.pory"

# 65 "data/maps/Route118/scripts.pory"
Route118_EventScript_StevenTrigger0::
# 66 "data/maps/Route118/scripts.pory"
	lockall
# 67 "data/maps/Route118/scripts.pory"
	setvar VAR_0x8008, 0
# 68 "data/maps/Route118/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 69 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 70 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_STEVEN, Route118_Movement_StevenApproachLedge0
# 71 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 72 "data/maps/Route118/scripts.pory"
	goto Route118_EventScript_StevenTrigger
# 73 "data/maps/Route118/scripts.pory"
	end
# 74 "data/maps/Route118/scripts.pory"

# 75 "data/maps/Route118/scripts.pory"
Route118_EventScript_StevenTrigger1::
# 76 "data/maps/Route118/scripts.pory"
	lockall
# 77 "data/maps/Route118/scripts.pory"
	setvar VAR_0x8008, 1
# 78 "data/maps/Route118/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 79 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 80 "data/maps/Route118/scripts.pory"
	goto Route118_EventScript_StevenTrigger
# 81 "data/maps/Route118/scripts.pory"
	end
# 82 "data/maps/Route118/scripts.pory"

# 83 "data/maps/Route118/scripts.pory"
Route118_EventScript_StevenTrigger2::
# 84 "data/maps/Route118/scripts.pory"
	lockall
# 85 "data/maps/Route118/scripts.pory"
	setvar VAR_0x8008, 2
# 86 "data/maps/Route118/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 87 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 88 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_STEVEN, Route118_Movement_StevenApproachLedge2
# 89 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 90 "data/maps/Route118/scripts.pory"
	goto Route118_EventScript_StevenTrigger
# 91 "data/maps/Route118/scripts.pory"
	end
# 92 "data/maps/Route118/scripts.pory"

# 93 "data/maps/Route118/scripts.pory"
Route118_EventScript_StevenTrigger::
# 94 "data/maps/Route118/scripts.pory"
	playse SE_LEDGE
# 95 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_STEVEN, Route118_Movement_StevenJumpLedge
# 96 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 97 "data/maps/Route118/scripts.pory"
	delay 30
# 98 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_StevenQuestions, MSGBOX_DEFAULT
# 99 "data/maps/Route118/scripts.pory"
	closemessage
# 100 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_0x8008, 0, Route118_EventScript_StevenExit0
# 101 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_0x8008, 1, Route118_EventScript_StevenExit1
# 102 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_0x8008, 2, Route118_EventScript_StevenExit2
# 103 "data/maps/Route118/scripts.pory"
	setvar VAR_ROUTE118_STATE, 1
# 104 "data/maps/Route118/scripts.pory"
	removeobject LOCALID_STEVEN
# 105 "data/maps/Route118/scripts.pory"
	releaseall
# 106 "data/maps/Route118/scripts.pory"
	end
# 107 "data/maps/Route118/scripts.pory"

# 108 "data/maps/Route118/scripts.pory"
Route118_EventScript_StevenExit0::
# 109 "data/maps/Route118/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerWatchStevenExit
# 110 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit0
# 111 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 112 "data/maps/Route118/scripts.pory"
	return
# 113 "data/maps/Route118/scripts.pory"

# 114 "data/maps/Route118/scripts.pory"
Route118_EventScript_StevenExit1::
# 115 "data/maps/Route118/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerWatchStevenExit
# 116 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit1
# 117 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 118 "data/maps/Route118/scripts.pory"
	return
# 119 "data/maps/Route118/scripts.pory"

# 120 "data/maps/Route118/scripts.pory"
Route118_EventScript_StevenExit2::
# 121 "data/maps/Route118/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerWatchStevenExit
# 122 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit2
# 123 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 124 "data/maps/Route118/scripts.pory"
	return
# 125 "data/maps/Route118/scripts.pory"

# 126 "data/maps/Route118/scripts.pory"
Route118_Movement_PlayerWatchStevenExit:
# 127 "data/maps/Route118/scripts.pory"
	delay_16
# 128 "data/maps/Route118/scripts.pory"
	walk_in_place_faster_right
# 129 "data/maps/Route118/scripts.pory"
	step_end
# 130 "data/maps/Route118/scripts.pory"

# 131 "data/maps/Route118/scripts.pory"
Route118_Movement_StevenApproachLedge0:
# 132 "data/maps/Route118/scripts.pory"
	walk_left
# 133 "data/maps/Route118/scripts.pory"
	step_end
# 134 "data/maps/Route118/scripts.pory"

# 135 "data/maps/Route118/scripts.pory"
Route118_Movement_StevenApproachLedge2:
# 136 "data/maps/Route118/scripts.pory"
	walk_right
# 137 "data/maps/Route118/scripts.pory"
	step_end
# 138 "data/maps/Route118/scripts.pory"

# 139 "data/maps/Route118/scripts.pory"
Route118_Movement_StevenJumpLedge:
# 140 "data/maps/Route118/scripts.pory"
	jump_2_down
# 141 "data/maps/Route118/scripts.pory"
	delay_16
# 142 "data/maps/Route118/scripts.pory"
	walk_down
# 143 "data/maps/Route118/scripts.pory"
	step_end
# 144 "data/maps/Route118/scripts.pory"

# 145 "data/maps/Route118/scripts.pory"
Route118_Movement_StevenExit0:
# 146 "data/maps/Route118/scripts.pory"
	walk_right
# 147 "data/maps/Route118/scripts.pory"
	walk_right
# 148 "data/maps/Route118/scripts.pory"
	walk_right
# 149 "data/maps/Route118/scripts.pory"
	walk_right
# 150 "data/maps/Route118/scripts.pory"
	walk_right
# 151 "data/maps/Route118/scripts.pory"
	walk_right
# 152 "data/maps/Route118/scripts.pory"
	walk_right
# 153 "data/maps/Route118/scripts.pory"
	walk_right
# 154 "data/maps/Route118/scripts.pory"
	walk_right
# 155 "data/maps/Route118/scripts.pory"
	walk_right
# 156 "data/maps/Route118/scripts.pory"
	step_end
# 157 "data/maps/Route118/scripts.pory"

# 158 "data/maps/Route118/scripts.pory"
Route118_Movement_StevenExit1:
# 159 "data/maps/Route118/scripts.pory"
	walk_right
# 160 "data/maps/Route118/scripts.pory"
	walk_right
# 161 "data/maps/Route118/scripts.pory"
	walk_right
# 162 "data/maps/Route118/scripts.pory"
	walk_right
# 163 "data/maps/Route118/scripts.pory"
	walk_right
# 164 "data/maps/Route118/scripts.pory"
	walk_right
# 165 "data/maps/Route118/scripts.pory"
	walk_right
# 166 "data/maps/Route118/scripts.pory"
	walk_right
# 167 "data/maps/Route118/scripts.pory"
	walk_right
# 168 "data/maps/Route118/scripts.pory"
	step_end
# 169 "data/maps/Route118/scripts.pory"

# 170 "data/maps/Route118/scripts.pory"
Route118_Movement_StevenExit2:
# 171 "data/maps/Route118/scripts.pory"
	walk_right
# 172 "data/maps/Route118/scripts.pory"
	walk_right
# 173 "data/maps/Route118/scripts.pory"
	walk_right
# 174 "data/maps/Route118/scripts.pory"
	walk_right
# 175 "data/maps/Route118/scripts.pory"
	walk_right
# 176 "data/maps/Route118/scripts.pory"
	walk_right
# 177 "data/maps/Route118/scripts.pory"
	walk_right
# 178 "data/maps/Route118/scripts.pory"
	walk_right
# 179 "data/maps/Route118/scripts.pory"
	step_end
# 180 "data/maps/Route118/scripts.pory"

# 181 "data/maps/Route118/scripts.pory"
Route118_EventScript_Rose::
# 182 "data/maps/Route118/scripts.pory"
	trainerbattle_single TRAINER_ROSE_1, Route118_Text_RoseIntro, Route118_Text_RoseDefeat, Route118_EventScript_RegisterRose
# 183 "data/maps/Route118/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 184 "data/maps/Route118/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route118_EventScript_RematchRose
# 185 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_RosePostBattle, MSGBOX_DEFAULT
# 186 "data/maps/Route118/scripts.pory"
	release
# 187 "data/maps/Route118/scripts.pory"
	end
# 188 "data/maps/Route118/scripts.pory"

# 189 "data/maps/Route118/scripts.pory"
Route118_EventScript_RegisterRose::
# 190 "data/maps/Route118/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 191 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 192 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_RoseRegister, MSGBOX_DEFAULT
# 193 "data/maps/Route118/scripts.pory"
	register_matchcall TRAINER_ROSE_1
# 194 "data/maps/Route118/scripts.pory"
	release
# 195 "data/maps/Route118/scripts.pory"
	end
# 196 "data/maps/Route118/scripts.pory"

# 197 "data/maps/Route118/scripts.pory"
Route118_EventScript_RematchRose::
# 198 "data/maps/Route118/scripts.pory"
	trainerbattle_rematch TRAINER_ROSE_1, Route118_Text_RoseRematchIntro, Route118_Text_RoseRematchDefeat
# 199 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_RosePostRematch, MSGBOX_AUTOCLOSE
# 200 "data/maps/Route118/scripts.pory"
	end
# 201 "data/maps/Route118/scripts.pory"

# 202 "data/maps/Route118/scripts.pory"
Route118_EventScript_Barny::
# 203 "data/maps/Route118/scripts.pory"
	trainerbattle_single TRAINER_BARNY, Route118_Text_BarnyIntro, Route118_Text_BarnyDefeat
# 204 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_BarnyPostBattle, MSGBOX_AUTOCLOSE
# 205 "data/maps/Route118/scripts.pory"
	end
# 206 "data/maps/Route118/scripts.pory"

# 207 "data/maps/Route118/scripts.pory"
Route118_EventScript_Wade::
# 208 "data/maps/Route118/scripts.pory"
	trainerbattle_single TRAINER_WADE, Route118_Text_WadeIntro, Route118_Text_WadeDefeat
# 209 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_WadePostBattle, MSGBOX_AUTOCLOSE
# 210 "data/maps/Route118/scripts.pory"
	end
# 211 "data/maps/Route118/scripts.pory"

# 212 "data/maps/Route118/scripts.pory"
Route118_EventScript_Dalton::
# 213 "data/maps/Route118/scripts.pory"
	trainerbattle_single TRAINER_DALTON_1, Route118_Text_DaltonIntro, Route118_Text_DaltonDefeat, Route118_EventScript_RegisterDalton
# 214 "data/maps/Route118/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 215 "data/maps/Route118/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route118_EventScript_RematchDalton
# 216 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_DaltonPostBattle, MSGBOX_DEFAULT
# 217 "data/maps/Route118/scripts.pory"
	release
# 218 "data/maps/Route118/scripts.pory"
	end
# 219 "data/maps/Route118/scripts.pory"

# 220 "data/maps/Route118/scripts.pory"
Route118_EventScript_RegisterDalton::
# 221 "data/maps/Route118/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 222 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 223 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_DaltonRegister, MSGBOX_DEFAULT
# 224 "data/maps/Route118/scripts.pory"
	register_matchcall TRAINER_DALTON_1
# 225 "data/maps/Route118/scripts.pory"
	release
# 226 "data/maps/Route118/scripts.pory"
	end
# 227 "data/maps/Route118/scripts.pory"

# 228 "data/maps/Route118/scripts.pory"
Route118_EventScript_RematchDalton::
# 229 "data/maps/Route118/scripts.pory"
	trainerbattle_rematch TRAINER_DALTON_1, Route118_Text_DaltonRematchIntro, Route118_Text_DaltonRematchDefeat
# 230 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_DaltonPostRematch, MSGBOX_AUTOCLOSE
# 231 "data/maps/Route118/scripts.pory"
	end
# 232 "data/maps/Route118/scripts.pory"

# 233 "data/maps/Route118/scripts.pory"
Route118_EventScript_Perry::
# 234 "data/maps/Route118/scripts.pory"
	trainerbattle_single TRAINER_PERRY, Route118_Text_PerryIntro, Route118_Text_PerryDefeat
# 235 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_PerryPostBattle, MSGBOX_AUTOCLOSE
# 236 "data/maps/Route118/scripts.pory"
	end
# 237 "data/maps/Route118/scripts.pory"

# 238 "data/maps/Route118/scripts.pory"
Route118_EventScript_Chester::
# 239 "data/maps/Route118/scripts.pory"
	trainerbattle_single TRAINER_CHESTER, Route118_Text_ChesterIntro, Route118_Text_ChesterDefeat
# 240 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_ChesterPostBattle, MSGBOX_AUTOCLOSE
# 241 "data/maps/Route118/scripts.pory"
	end
# 242 "data/maps/Route118/scripts.pory"

# 243 "data/maps/Route118/scripts.pory"
Route118_EventScript_Deandre::
# 244 "data/maps/Route118/scripts.pory"
	trainerbattle_single TRAINER_DEANDRE, Route118_Text_DeandreIntro, Route118_Text_DeandreDefeat
# 245 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_DeandrePostBattle, MSGBOX_AUTOCLOSE
# 246 "data/maps/Route118/scripts.pory"
	end
# 247 "data/maps/Route118/scripts.pory"

# 248 "data/maps/Route118/scripts.pory"
Route118_Text_StevenQuestions:
# 249 "data/maps/Route118/scripts.pory"
	.string "STEVEN: Hi, {PLAYER}{KUN}!\p"
# 250 "data/maps/Route118/scripts.pory"
	.string "It's me, STEVEN!\n"
# 251 "data/maps/Route118/scripts.pory"
	.string "We met in the cave near DEWFORD.\p"
# 252 "data/maps/Route118/scripts.pory"
	.string "Have you met many kinds of POKéMON\n"
# 253 "data/maps/Route118/scripts.pory"
	.string "since I last saw you?\p"
# 254 "data/maps/Route118/scripts.pory"
	.string "There are many, many kinds of POKéMON\n"
# 255 "data/maps/Route118/scripts.pory"
	.string "in this wide world of ours.\p"
# 256 "data/maps/Route118/scripts.pory"
	.string "If you wanted to raise only your\n"
# 257 "data/maps/Route118/scripts.pory"
	.string "favorites, that's fine.\p"
# 258 "data/maps/Route118/scripts.pory"
	.string "Perhaps you find it more fun to raise\n"
# 259 "data/maps/Route118/scripts.pory"
	.string "all sorts of POKéMON.\p"
# 260 "data/maps/Route118/scripts.pory"
	.string "As a TRAINER of POKéMON,\n"
# 261 "data/maps/Route118/scripts.pory"
	.string "what do you think?\p"
# 262 "data/maps/Route118/scripts.pory"
	.string "Of course, it's not any of my business.\p"
# 263 "data/maps/Route118/scripts.pory"
	.string "It would be nice if we were to meet\n"
# 264 "data/maps/Route118/scripts.pory"
	.string "again somewhere.$"
# 265 "data/maps/Route118/scripts.pory"

# 266 "data/maps/Route118/scripts.pory"
Route118_Text_YouAgreeGoodRodIsGood:
# 267 "data/maps/Route118/scripts.pory"
	.string "Hmm!\n"
# 268 "data/maps/Route118/scripts.pory"
	.string "A GOOD ROD is really good!\p"
# 269 "data/maps/Route118/scripts.pory"
	.string "Wouldn't you agree?$"
# 270 "data/maps/Route118/scripts.pory"

# 271 "data/maps/Route118/scripts.pory"
Route118_Text_IdenticalMindsTakeThis:
# 272 "data/maps/Route118/scripts.pory"
	.string "Hmm!\n"
# 273 "data/maps/Route118/scripts.pory"
	.string "We're of identical minds!\p"
# 274 "data/maps/Route118/scripts.pory"
	.string "Hmm!\n"
# 275 "data/maps/Route118/scripts.pory"
	.string "Take this GOOD ROD!$"
# 276 "data/maps/Route118/scripts.pory"

# 277 "data/maps/Route118/scripts.pory"
Route118_Text_TryYourLuckFishing:
# 278 "data/maps/Route118/scripts.pory"
	.string "Wherever there's water, try your luck\n"
# 279 "data/maps/Route118/scripts.pory"
	.string "at fishing.$"
# 280 "data/maps/Route118/scripts.pory"

# 281 "data/maps/Route118/scripts.pory"
Route118_Text_DontYouLikeToFish:
# 282 "data/maps/Route118/scripts.pory"
	.string "Don't you like to fish?$"
# 283 "data/maps/Route118/scripts.pory"

# 284 "data/maps/Route118/scripts.pory"
Route118_Text_TryCatchingMonWithGoodRod:
# 285 "data/maps/Route118/scripts.pory"
	.string "Try catching all sorts of POKéMON\n"
# 286 "data/maps/Route118/scripts.pory"
	.string "with your GOOD ROD.$"
# 287 "data/maps/Route118/scripts.pory"

# 288 "data/maps/Route118/scripts.pory"
Route118_Text_CanCrossRiversWithSurf:
# 289 "data/maps/Route118/scripts.pory"
	.string "Even if there isn't a boat, you can\n"
# 290 "data/maps/Route118/scripts.pory"
	.string "cross rivers and the sea if you have\l"
# 291 "data/maps/Route118/scripts.pory"
	.string "a POKéMON that knows SURF.\p"
# 292 "data/maps/Route118/scripts.pory"
	.string "POKéMON can be counted on to do so\n"
# 293 "data/maps/Route118/scripts.pory"
	.string "much!$"
# 294 "data/maps/Route118/scripts.pory"

# 295 "data/maps/Route118/scripts.pory"
Route118_Text_RouteSignMauville:
# 296 "data/maps/Route118/scripts.pory"
	.string "ROUTE 118\n"
# 297 "data/maps/Route118/scripts.pory"
	.string "{LEFT_ARROW} MAUVILLE CITY$"
# 298 "data/maps/Route118/scripts.pory"

# 299 "data/maps/Route118/scripts.pory"
Route118_Text_RouteSign119:
# 300 "data/maps/Route118/scripts.pory"
	.string "ROUTE 118\n"
# 301 "data/maps/Route118/scripts.pory"
	.string "{UP_ARROW} ROUTE 119$"
