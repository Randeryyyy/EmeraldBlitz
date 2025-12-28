InsideOfTruck_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, InsideOfTruck_OnLoad
	.byte 0

InsideOfTruck_OnLoad:
	setmetatile 4, 1, METATILE_InsideOfTruck_DoorClosedFloor_Top, FALSE
	setmetatile 4, 2, METATILE_InsideOfTruck_DoorClosedFloor_Mid, FALSE
	setmetatile 4, 3, METATILE_InsideOfTruck_DoorClosedFloor_Bottom, FALSE
	end

InsideOfTruck_EventScript_KommooCry::
	lockall
	msgbox InsideOfTruck_Text_SideEye, MSGBOX_SIGN
	releaseall
	end

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

InsideOfTruck_Text_SideEye:
	.string "………\p"
	.string "………………………\p"
	.string "…………………………………………………………………………\p"
	.string "KOMMO-O is giving you some judgmental\n"
	.string "side eye.\p"
	.string "…………\p"
	.string "…Well, this sure is awkward.$"
