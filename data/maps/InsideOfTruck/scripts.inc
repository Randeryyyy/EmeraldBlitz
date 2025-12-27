InsideOfTruck_MapScripts::
	.byte 0

InsideOfTruck_OnLoad:
	setmetatile 4, 1, METATILE_InsideOfTruck_ExitLight_Top, TRUE
	setmetatile 4, 2, METATILE_InsideOfTruck_ExitLight_Mid, TRUE
	setmetatile 4, 3, METATILE_InsideOfTruck_ExitLight_Bottom, TRUE
	end

InsideOfTruck_EventScript_KommooCry::
	lock
	msgbox InsideOfTruck_Text_SideEye, MSGBOX_NPC
	release
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
	.string "…\p"
	.string "…………\p"
	.string "…………………………………………\p"
	.string "KOMMO-O is giving you some judgmental\n"
	.string "side eye.\p"
	.string "…………\p"
	.string "…Well, this sure is awkward.$"
