# 1 "data/maps/MirageTower_4F/scripts.pory"

# 2 "data/maps/MirageTower_4F/scripts.pory"
.set LOCALID_ROOT_FOSSIL, 1
# 3 "data/maps/MirageTower_4F/scripts.pory"
.set LOCALID_CLAW_FOSSIL, 2
# 4 "data/maps/MirageTower_4F/scripts.pory"

# 5 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_MapScripts::
# 6 "data/maps/MirageTower_4F/scripts.pory"
	.byte 0
# 7 "data/maps/MirageTower_4F/scripts.pory"

# 8 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_EventScript_RootFossil::
# 9 "data/maps/MirageTower_4F/scripts.pory"
	lock
# 10 "data/maps/MirageTower_4F/scripts.pory"
	faceplayer
# 11 "data/maps/MirageTower_4F/scripts.pory"
	msgbox MirageTower_4F_Text_TakeRootFossil, MSGBOX_YESNO
# 12 "data/maps/MirageTower_4F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MirageTower_4F_EventScript_LeaveRootFossil
# 13 "data/maps/MirageTower_4F/scripts.pory"
	giveitem ITEM_ROOT_FOSSIL
# 14 "data/maps/MirageTower_4F/scripts.pory"
	closemessage
# 15 "data/maps/MirageTower_4F/scripts.pory"
	setflag FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL
# 16 "data/maps/MirageTower_4F/scripts.pory"
	setflag FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL
# 17 "data/maps/MirageTower_4F/scripts.pory"
	removeobject LOCALID_ROOT_FOSSIL
# 18 "data/maps/MirageTower_4F/scripts.pory"
	delay 30
# 19 "data/maps/MirageTower_4F/scripts.pory"
	setflag FLAG_CHOSE_ROOT_FOSSIL
# 20 "data/maps/MirageTower_4F/scripts.pory"
	goto MirageTower_4F_EventScript_CollapseMirageTower
# 21 "data/maps/MirageTower_4F/scripts.pory"
	end
# 22 "data/maps/MirageTower_4F/scripts.pory"

# 23 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_EventScript_LeaveRootFossil::
# 24 "data/maps/MirageTower_4F/scripts.pory"
	msgbox MirageTower_4F_Text_LeftRootFossilAlone, MSGBOX_DEFAULT
# 25 "data/maps/MirageTower_4F/scripts.pory"
	release
# 26 "data/maps/MirageTower_4F/scripts.pory"
	end
# 27 "data/maps/MirageTower_4F/scripts.pory"

# 28 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_EventScript_ClawFossil::
# 29 "data/maps/MirageTower_4F/scripts.pory"
	lock
# 30 "data/maps/MirageTower_4F/scripts.pory"
	faceplayer
# 31 "data/maps/MirageTower_4F/scripts.pory"
	msgbox MirageTower_4F_Text_TakeClawFossil, MSGBOX_YESNO
# 32 "data/maps/MirageTower_4F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MirageTower_4F_EventScript_LeaveClawFossil
# 33 "data/maps/MirageTower_4F/scripts.pory"
	giveitem ITEM_CLAW_FOSSIL
# 34 "data/maps/MirageTower_4F/scripts.pory"
	closemessage
# 35 "data/maps/MirageTower_4F/scripts.pory"
	setflag FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL
# 36 "data/maps/MirageTower_4F/scripts.pory"
	setflag FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL
# 37 "data/maps/MirageTower_4F/scripts.pory"
	removeobject LOCALID_CLAW_FOSSIL
# 38 "data/maps/MirageTower_4F/scripts.pory"
	delay 30
# 39 "data/maps/MirageTower_4F/scripts.pory"
	setflag FLAG_CHOSE_CLAW_FOSSIL
# 40 "data/maps/MirageTower_4F/scripts.pory"
	goto MirageTower_4F_EventScript_CollapseMirageTower
# 41 "data/maps/MirageTower_4F/scripts.pory"
	end
# 42 "data/maps/MirageTower_4F/scripts.pory"

# 43 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_EventScript_LeaveClawFossil::
# 44 "data/maps/MirageTower_4F/scripts.pory"
	msgbox MirageTower_4F_Text_LeaveClawFossilAlone, MSGBOX_DEFAULT
# 45 "data/maps/MirageTower_4F/scripts.pory"
	release
# 46 "data/maps/MirageTower_4F/scripts.pory"
	end
# 47 "data/maps/MirageTower_4F/scripts.pory"

# 48 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_EventScript_CollapseMirageTower::
# 49 "data/maps/MirageTower_4F/scripts.pory"
	setvar VAR_0x8004, 1   @ vertical pan
# 50 "data/maps/MirageTower_4F/scripts.pory"
	setvar VAR_0x8005, 1   @ horizontal pan
# 51 "data/maps/MirageTower_4F/scripts.pory"
	setvar VAR_0x8006, 32  @ num shakes
# 52 "data/maps/MirageTower_4F/scripts.pory"
	setvar VAR_0x8007, 2   @ shake delay
# 53 "data/maps/MirageTower_4F/scripts.pory"
	special ShakeCamera
# 54 "data/maps/MirageTower_4F/scripts.pory"
	waitstate
# 55 "data/maps/MirageTower_4F/scripts.pory"
	special DoMirageTowerCeilingCrumble
# 56 "data/maps/MirageTower_4F/scripts.pory"
	waitstate
# 57 "data/maps/MirageTower_4F/scripts.pory"
	setvar VAR_MIRAGE_TOWER_STATE, 1
# 58 "data/maps/MirageTower_4F/scripts.pory"
	clearflag FLAG_LANDMARK_MIRAGE_TOWER
# 59 "data/maps/MirageTower_4F/scripts.pory"
	warp MAP_ROUTE111, 19, 59
# 60 "data/maps/MirageTower_4F/scripts.pory"
	waitstate
# 61 "data/maps/MirageTower_4F/scripts.pory"
	release
# 62 "data/maps/MirageTower_4F/scripts.pory"
	end
# 63 "data/maps/MirageTower_4F/scripts.pory"

# 64 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_Text_TakeRootFossil:
# 65 "data/maps/MirageTower_4F/scripts.pory"
	.string "You found the ROOT FOSSIL.\p"
# 66 "data/maps/MirageTower_4F/scripts.pory"
	.string "If this FOSSIL is taken, the ground\n"
# 67 "data/maps/MirageTower_4F/scripts.pory"
	.string "around it will likely crumble away…\p"
# 68 "data/maps/MirageTower_4F/scripts.pory"
	.string "Take the ROOT FOSSIL anyway?$"
# 69 "data/maps/MirageTower_4F/scripts.pory"

# 70 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_Text_LeftRootFossilAlone:
# 71 "data/maps/MirageTower_4F/scripts.pory"
	.string "{PLAYER} left the ROOT FOSSIL alone.$"
# 72 "data/maps/MirageTower_4F/scripts.pory"

# 73 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_Text_TakeClawFossil:
# 74 "data/maps/MirageTower_4F/scripts.pory"
	.string "You found the CLAW FOSSIL.\p"
# 75 "data/maps/MirageTower_4F/scripts.pory"
	.string "If this FOSSIL is taken, the ground\n"
# 76 "data/maps/MirageTower_4F/scripts.pory"
	.string "around it will likely crumble away…\p"
# 77 "data/maps/MirageTower_4F/scripts.pory"
	.string "Take the CLAW FOSSIL anyway?$"
# 78 "data/maps/MirageTower_4F/scripts.pory"

# 79 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_Text_LeaveClawFossilAlone:
# 80 "data/maps/MirageTower_4F/scripts.pory"
	.string "{PLAYER} left the CLAW FOSSIL alone.$"
