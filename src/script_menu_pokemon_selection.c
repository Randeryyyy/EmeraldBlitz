#include "global.h"
#include "script.h"
#include "random.h"
#include "script_menu.h"
#include "string_util.h"
#include "strings.h"
#include "pokemon.h"
#include "constants/species.h"
#include "data/pokemon/form_species_tables.h"
#include "constants/flags.h"
#include "event_data.h"

static const u8 sText_MysteryEgg[] = _("Mystery Egg");

static const u16 sGiftPokemonList[] = {
    SPECIES_APPLIN, 
    SPECIES_ARCHEN,
    SPECIES_ARON, 
    SPECIES_BAGON, 
    SPECIES_BELDUM,
    SPECIES_BUIZEL,
    SPECIES_BUNEARY, 
    SPECIES_BUNNELBY, 
    SPECIES_CACNEA, 
    SPECIES_CARVANHA, 
    SPECIES_CASTFORM,
    SPECIES_CHESPIN,
    SPECIES_CHEWTLE,
    SPECIES_CHINCHOU, 
    SPECIES_CORPHISH, 
    SPECIES_CORSOLA,
    SPECIES_CUBONE, 
    SPECIES_CUTIEFLY,
    SPECIES_DEWPIDER,
    SPECIES_DIGLETT, 
    SPECIES_DRILBUR, 
    SPECIES_ELECTRIKE, 
    SPECIES_EXEGGCUTE, 
    SPECIES_FEEBAS,
    SPECIES_FENNEKIN,
    SPECIES_FIDOUGH,
    SPECIES_FLABEBE, 
    SPECIES_FLETCHLING, 
    SPECIES_FROAKIE, 
    SPECIES_FUECOCO, 
    SPECIES_GEODUDE,
    SPECIES_GIBLE, 
    SPECIES_GOOMY, 
    SPECIES_GOSSIFLEUR,
    SPECIES_GREAVARD, 
    SPECIES_GROWLITHE,
    SPECIES_GRUBBIN, 
    SPECIES_HATENNA,
    SPECIES_HELIOPTILE, 
    SPECIES_HONEDGE,
    SPECIES_HORSEA,
    SPECIES_HOUNDOUR,
    SPECIES_JANGMO_O,
    SPECIES_JOLTIK,
    SPECIES_LITTEN, 
    SPECIES_LITWICK, 
    SPECIES_MAGNEMITE,
    SPECIES_MAKUHITA, 
    SPECIES_MANKEY, 
    SPECIES_MAREEP,
    SPECIES_MAWILE,
    SPECIES_MEOWTH_GALAR, 
    SPECIES_MINCCINO,
    SPECIES_MINIOR_CORE,
    SPECIES_MORELULL, 
    SPECIES_MUDBRAY, 
    SPECIES_MUDKIP,
    SPECIES_MURKROW,
    SPECIES_NINCADA,
    SPECIES_NOIBAT, 
    SPECIES_NUMEL, 
    SPECIES_ODDISH, 
    SPECIES_PANCHAM,
    SPECIES_PIKIPEK, 
    SPECIES_POLIWAG, 
    SPECIES_POOCHYENA, 
    SPECIES_POPPLIO, 
    SPECIES_PORYGON,
    SPECIES_RALTS, 
    SPECIES_ROCKRUFF, 
    SPECIES_ROLYCOLY,
    SPECIES_ROTOM, 
    SPECIES_ROWLET, 
    SPECIES_SABLEYE,
    SPECIES_SALANDIT, 
    SPECIES_SANDILE,
    SPECIES_SANDSHREW_ALOLA,
    SPECIES_SCATTERBUG, 
    SPECIES_SCYTHER,
    SPECIES_SEWADDLE,
    SPECIES_SHELLDER,
    SPECIES_SHINX, 
    SPECIES_SHROOMISH,
    SPECIES_SHUPPET, 
    SPECIES_SKIDDO, 
    SPECIES_SKRELP,
    SPECIES_SLOWPOKE_GALAR, 
    SPECIES_SMOLIV,
    SPECIES_SNORUNT, 
    SPECIES_SOLOSIS, 
    SPECIES_SPHEAL, 
    SPECIES_SPOINK,
    SPECIES_STARYU, 
    SPECIES_SURSKIT,
    SPECIES_SWINUB,
    SPECIES_TEDDIURSA, 
    SPECIES_TENTACOOL,
    SPECIES_TIMBURR,
    SPECIES_TINKATINK, 
    SPECIES_TORCHIC, 
    SPECIES_TOTODILE,
    SPECIES_TRAPINCH, 
    SPECIES_TREECKO, 
    SPECIES_TRUBBISH,
    SPECIES_TURTWIG, 
    SPECIES_TYRUNT,
    SPECIES_VENIPEDE, 
    SPECIES_VULPIX_ALOLA, 
    SPECIES_WINGULL, 
    SPECIES_WISHIWASHI,
    SPECIES_WOOPER_PALDEA, 
    SPECIES_ZIGZAGOON_GALAR, 
    SPECIES_ZORUA,
    SPECIES_ZUBAT,
    SPECIES_EGG
};

// This function builds the list of Pokémon for the multichoice menu.
void BuildGiftPokemonMenu(void)
{
    u32 i;
    u16 species;

    ScriptMenu_ClearDynMultichoice();

    for (i = 0; i < ARRAY_COUNT(sGiftPokemonList); i++)
    {
        species = sGiftPokemonList[i];
        if (species == SPECIES_MINIOR_CORE)
        {
            species = SPECIES_MINIOR_CORE_RED + (Random() % (SPECIES_MINIOR_CORE_VIOLET - SPECIES_MINIOR_CORE_RED + 1));
            ScriptMenu_AddDynmultichoice(gSpeciesInfo[SPECIES_MINIOR].speciesName, species, 0);
        }
        else if (species == SPECIES_SCATTERBUG)
        {
            species = sScatterbugFormSpeciesIdTable[Random() % (ARRAY_COUNT(sScatterbugFormSpeciesIdTable) - 1)];
            ScriptMenu_AddDynmultichoice(gSpeciesInfo[SPECIES_SCATTERBUG].speciesName, species, 0);
        }
        else if (species == SPECIES_EGG)
            ScriptMenu_AddDynmultichoice(sText_MysteryEgg, species, 0);
        else
            ScriptMenu_AddDynmultichoice(gSpeciesInfo[species].speciesName, species, 0);
    }

    ScriptMenu_AddDynmultichoice(gText_Finished, 999, -1);
}
