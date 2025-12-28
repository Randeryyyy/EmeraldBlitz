@
@ NOTE: The moving boxes are objects 1, 2, and 3.
#define LOCALID_KOMMOO 4
#define LOCALID_SHUPPET_1 5
#define LOCALID_SHUPPET_2 6
#define LOCALID_SHUPPET_3 7
#define LOCALID_SHUPPET_4 8
#define LOCALID_SHUPPET_5 9
#define LOCALID_SHUPPET_6 10
#define LOCALID_JELLICENT_1 11
#define LOCALID_JELLICENT_2 12
#define LOCALID_JELLICENT_3 13
#define LOCALID_JELLICENT_4 14
#define LOCALID_JELLICENT_5 15
#define LOCALID_JELLICENT_6 16
#define LOCALID_JELLICENT_7 17
#define LOCALID_JELLICENT_8 18
#define LOCALID_JELLICENT_9 19
#define LOCALID_JELLICENT_10 20
#define LOCALID_JELLICENT_11 21
#define LOCALID_LOUDRED 22
#define LOCALID_CASTFORM 23
#define LOCALID_EXEGGUTOR 24
#define LOCALID_MIMIKYU 25

InsideOfTruck_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, InsideOfTruck_OnLoad
	.byte 0

InsideOfTruck_OnLoad:
	setweather WEATHER_NONE
	doweather
	setmetatile 4, 1, METATILE_InsideOfTruck_DoorClosedFloor_Top, FALSE
	setmetatile 4, 2, METATILE_InsideOfTruck_DoorClosedFloor_Mid, FALSE
	setmetatile 4, 3, METATILE_InsideOfTruck_DoorClosedFloor_Bottom, FALSE
	@ Hide all scenario NPCs by default. They will only appear if their flag is cleared.
	setflag FLAG_HIDE_TRUCK_KOMMOO
	setflag FLAG_HIDE_TRUCK_SHUPPET
	setflag FLAG_HIDE_TRUCK_JELLICENT
	setflag FLAG_HIDE_TRUCK_LOUDRED
	setflag FLAG_HIDE_TRUCK_CASTFORM
	setflag FLAG_HIDE_TRUCK_EXEGGUTOR
	setflag FLAG_HIDE_TRUCK_MIMIKYU
	@ Randomly select a scenario and un-hide the corresponding NPCs
	random 7 @ Number of scenarios
	switch VAR_RESULT
	case 0, InsideOfTruck_EventScript_SetupKommoo
	case 1, InsideOfTruck_EventScript_SetupShuppets
	case 2, InsideOfTruck_EventScript_SetupJellicents
	case 3, InsideOfTruck_EventScript_SetupLoudred
	case 4, InsideOfTruck_EventScript_SetupCastform
	case 5, InsideOfTruck_EventScript_SetupExeggutor
	case 6, InsideOfTruck_EventScript_SetupMimikyu
	end

InsideOfTruck_EventScript_SetupKommoo::
	clearflag FLAG_HIDE_TRUCK_KOMMOO
	return

InsideOfTruck_EventScript_SetupShuppets::
	clearflag FLAG_HIDE_TRUCK_SHUPPET
	return

InsideOfTruck_EventScript_SetupJellicents::
	clearflag FLAG_HIDE_TRUCK_JELLICENT
	return

InsideOfTruck_EventScript_SetupLoudred::
	clearflag FLAG_HIDE_TRUCK_LOUDRED
	return

InsideOfTruck_EventScript_SetupCastform::
	clearflag FLAG_HIDE_TRUCK_CASTFORM
	setweather WEATHER_RAIN
	doweather
	return

InsideOfTruck_EventScript_SetupExeggutor::
	clearflag FLAG_HIDE_TRUCK_EXEGGUTOR
	return

InsideOfTruck_EventScript_SetupMimikyu::
	setflashlevel 7
	clearflag FLAG_HIDE_TRUCK_MIMIKYU
	return

InsideOfTruck_EventScript_KommooCry::
	lock
	getdirectiontoface VAR_RESULT, LOCALID_KOMMOO, LOCALID_PLAYER
	compare VAR_RESULT, DIR_SOUTH @ Player is below
	call_if_eq InsideOfTruck_EventScript_KommooFaceWest
	compare VAR_RESULT, DIR_NORTH @ Player is above
	call_if_eq InsideOfTruck_EventScript_KommooFaceEast
	compare VAR_RESULT, DIR_WEST @ Player is to the left
	call_if_eq InsideOfTruck_EventScript_KommooFaceSouth
	compare VAR_RESULT, DIR_EAST @ Player is to the right
	call_if_eq InsideOfTruck_EventScript_KommooFaceNorth
	msgbox InsideOfTruck_Text_SideEye, MSGBOX_DEFAULT
	release
	end

InsideOfTruck_EventScript_KommooFaceWest::
	applymovement LOCALID_KOMMOO, InsideOfTruck_Movement_KommooFaceWest
	waitmovement 0
	return

InsideOfTruck_EventScript_KommooFaceSouth::
	applymovement LOCALID_KOMMOO, InsideOfTruck_Movement_KommooFaceSouth
	waitmovement 0
	return

InsideOfTruck_EventScript_KommooFaceEast::
	applymovement LOCALID_KOMMOO, InsideOfTruck_Movement_KommooFaceEast
	waitmovement 0
	return

InsideOfTruck_EventScript_KommooFaceNorth::
	applymovement LOCALID_KOMMOO, InsideOfTruck_Movement_KommooFaceNorth
	waitmovement 0
	return

InsideOfTruck_Movement_KommooFaceWest:
	walk_in_place_fast_left
	face_left
	step_end

InsideOfTruck_Movement_KommooFaceEast:
	walk_in_place_fast_right
	face_right
	step_end

InsideOfTruck_Movement_KommooFaceSouth:
	walk_in_place_fast_down
	face_down
	step_end

InsideOfTruck_Movement_KommooFaceNorth:
	walk_in_place_fast_up
	face_up
	step_end

InsideOfTruck_OnResume:
	setstepcallback STEP_CB_TRUCK
	end

InsideOfTruck_EventScript_SetIntroFlags::
	end

InsideOfTruck_EventScript_SetIntroFlagsMale::
	end

InsideOfTruck_EventScript_MovingBox::
	msgbox InsideOfTruck_Text_BoxPrintedWithMonLogo, MSGBOX_SIGN
	end

InsideOfTruck_Text_BoxPrintedWithMonLogo:
	.string "The box is printed with an EMERALD BLITZ\n"
	.string "logo.\p"
	.string "…\p"
	.string "It's filled to the brim with\n"
	.string "your hopes and dreams for this run.$"

InsideOfTruck_EventScript_Jellicent::
	lockall
	msgbox InsideOfTruck_Text_Jellicent, MSGBOX_SIGN
	releaseall
	end

InsideOfTruck_EventScript_Castform::
	lockall
	faceplayer
	msgbox InsideOfTruck_Text_Castform, MSGBOX_NPC
	releaseall
	end

InsideOfTruck_EventScript_Exeggutor::
	lockall
	msgbox InsideOfTruck_Text_Exeggutor, MSGBOX_SIGN
	releaseall
	end

InsideOfTruck_EventScript_Mimikyu::
	lock
	faceplayer
	msgbox InsideOfTruck_Text_Mimikyu, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	setflashlevel 8
	setflag FLAG_HIDE_TRUCK_MIMIKYU
	removeobject LOCALID_MIMIKYU
	playmoncry SPECIES_MIMIKYU, CRY_MODE_NORMAL
	waitmoncry
	waitstate

InsideOfTruck_Text_Exeggutor:
	.string "EXEGGUTOR seems to think it's being\n"
	.string "very sneaky.$"

InsideOfTruck_Text_Mimikyu:
	.string "The MIMIKYU is smiling at you\n"
	.string "menacingly.\p"
	.string "It seems to have been waiting for\n"
	.string "just this moment.$"

InsideOfTruck_Text_Castform:
	.string "CASTFORM appears to have set the\n"
	.string "weather based on your mood.$"

InsideOfTruck_Text_Jellicent:
	.string "……………\p"
	.string "…Well this is a little cramped.$"

InsideOfTruck_EventScript_Loudred::
	lockall
	faceplayer
	playmoncry SPECIES_LOUDRED, CRY_MODE_NORMAL
	waitmoncry
	msgbox InsideOfTruck_Text_Loudred, MSGBOX_NPC
	releaseall
	end

InsideOfTruck_Text_Loudred:
	.string "KRRRZZZZTBOOM BAMBAMBAMBAMBAM\n"
	.string "BWOOM BWOOM BWOOM VVVVVREEEEE\p"
	.string "LOUDRED is blasting noise so loud you\n"
	.string "can hardly hear yourself think.\p"
	.string "KRRRZZZZTBLAM KRRRZZZZTBLAM\p"
	.string "This is truly a fate worse than death.$"

InsideOfTruck_Text_SideEye:
	.string "………\p"
	.string "………………………\p"
	.string "…………………………………………………………………………\p"
	.string "KOMMO-O is giving you some judgmental\n"
	.string "side eye.\p"
	.string "…………\p"
	.string "…Well, this sure is awkward.$"

InsideOfTruck_EventScript_Shuppet1::
	lock
	faceplayer
	msgbox InsideOfTruck_Text_Shuppet1, MSGBOX_NPC
	release
	end

InsideOfTruck_EventScript_Shuppet2::
	lock
	faceplayer
	msgbox InsideOfTruck_Text_Shuppet2, MSGBOX_NPC
	release
	end

InsideOfTruck_EventScript_Shuppet3::
	lock
	faceplayer
	msgbox InsideOfTruck_Text_Shuppet3, MSGBOX_NPC
	release
	end

InsideOfTruck_Text_Shuppet1:
	.string "This SHUPPET seems to feel bad for you.$"

InsideOfTruck_Text_Shuppet2:
	.string "This SHUPPET seems to be amused by\n"
	.string "your failure.$"

InsideOfTruck_Text_Shuppet3:
	.string "This SHUPPET seems not to notice you.$"
