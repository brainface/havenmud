/*  Sew verb
 *  sews simple clothing from fabric/yarn
 *  sews bigglier clothing from fabric attached to a mannequin
 */
#include <lib.h>
#include <std.h>
#include <daemons.h>
#include <size.h>
inherit LIB_VERB;

// a mapping of size values to plain english.
mapping Sizes = ([
	"tiny" : SIZE_TINY,
	"small" : SIZE_SMALL,
	"very small" : SIZE_VERY_SMALL,
	"medium" : SIZE_MEDIUM,
	"large" : SIZE_LARGE,
	"very large" : SIZE_VERY_LARGE,
	"huge" : SIZE_HUGE,
	"giant" : SIZE_GIANT, 
]);

// this needs to be in an include file at some point.
mapping Patterns = ([
	"checked" : ({1, "checkerboard"}),
	"chevron" : ({25, "alternating chevron"}),
	"fleur-de-lis" : ({50, "fleur-de-lis"}),
	"brocade" : ({100, "detailed floral"}),
	"chinoiserie" : ({200, "detailed scenic"}),
]);

// name to file-name mapping
// i should probably use absolute paths but no.
mapping Garments = ([
  "sock" : "sock",
  "scarf" : "scarf",
  "tail wrap" : "tail_wrap",
  "shirt" : "shirt",
  "glove" : "glove",
  "hat" : "hat",
  "trousers" : "trousers",    
  "cloak" : "cloak",
  "robe" : "robe",
  "dress" : "dress",
  "skirt" : "skirt",
]);

static void create() {
  ::create();
  SetVerb("sew");
  SetRules("STR from OBJ with OBJ");
  SetErrorMessage("Sew what from what?");
  SetHelp(
    "Syntax:   sew [size] <garment> from <fabric> with <thread>\n"
    "Attempts to make the garment you specify from the materials you specify.\n"
    "You can make small garments anywhere, but larger clothing requires a the "
    "use of a sewing mannequin.\n"
    "The possible sizes are tiny, very small, small, medium, large, and very large.\n"
    "If unspecified, a garment of your size is made.\n"
  );
}

int eventCraft(string good, string size_text, object* materials, object who) {
  object garment;
  string adj;
  int lvl = 0;
  int bonus = 0;
  int maxLevel = 0;
  int size_value = 0;
  string* CraftMaterials = ({});
  string* CraftSources = ({});
  string* CraftColors = ({});
  string CraftPattern;

  // define garment size
  size_value = Sizes[size_text];  


  garment = new(STD_CRAFTING + "clothing/" + Garments[good]);
  
  if (!garment) {
    debug("Failed to create garment");
    return -1;
  }
  
  // check objects to make sure they're legit
  // we'll also do some math to determine material level
  foreach(object mat in materials) {
    if (!mat->GetMaterials() || !sizeof(mat->GetMaterials()) ) {
      debug("Bad sewing mat: " + mat->GetShort());
      return -1;		  
    }
    if (!mat->GetCraftSources() || !sizeof(mat->GetCraftSources()) ) {
      debug("Bad sewing mat sources: " + mat->GetShort());
      return -1;
    }
    bonus += mat->GetLevel();
    if (mat->GetCraftPattern()) CraftPattern = mat->GetCraftPattern();
    if (mat->GetLevel() > maxLevel) maxLevel = mat->GetLevel();
    foreach(string material in mat->GetMaterials() ) {
      CraftMaterials += ({ material });	
    }
    foreach(string source in mat->GetCraftSources() ) {
      CraftSources += ({ source });	
    }
    foreach(string color in mat->GetCraftColors() ) {
      CraftColors += ({ color });
    }
  }
  
  bonus /= sizeof(materials);
  bonus += who->GetLuck();
  
  // for each type of material in the material, test the player's relevant skill.
  // highest material level is the difficulty, average material level is a bonus
  // (if everything's equal level, this is a wash.)
  foreach(string mat_type in CraftMaterials ){
  	lvl += who->eventCheckSkill(mat_type + " working",maxLevel,bonus,0);  
  }
  
  // roughly will equal out crafter's skill level / 2
  lvl /= sizeof(CraftMaterials);
  
  // failed the skill check, so ruin the fabric (but not thread?)
  if (lvl < 1) {
  	 send_messages("ruin","$agent_name $agent_verb the $target_name", 
  	 	 who, materials[0], environment(who));
  	 materials[0]->eventDestruct();
  	 return 0;
  }
  
  switch(lvl) {
    case 1..4:
      adj = "roughly";
      break;
    case 5..20:
      adj = "carefully";
      break;
    case 21..50:
      adj = "quickly";
      break;
    case 51..150:
      adj = "skillfully";
      break;
    case 151..300:
      adj = "deftly";
      break;
    case 301..10000:
      adj = "flawlessly";
      break;
    default:
      adj = "crudely";
      break;
    }
    
  garment->SetLevel(lvl);  
  send_messages( ({ "sew" }),
    "$agent_name " + adj + " $agent_verb $target_name into a " + good, 
    who, materials[0], environment(who));
  garment->SetCraftMaterials(CraftMaterials);
  garment->SetCraftSources(CraftSources);
  garment->SetCraftPattern(CraftPattern);
  garment->SetCraftColors(CraftColors);
  materials[1]->eventDestruct();
  materials[0]->eventDestruct();
  if (who->CanCarry(garment->GetMass())) {
    garment->eventMove(who);
  } else {
    garment->eventMove(environment(who));
    who->eventPrint("The " + good + " is too heavy for you to carry right now.");
  }
  garment->SetCraftSize(size_value);
  garment->SetCraftedState();
}

mixed can_sew_str_from_obj_with_obj() {
  object who = this_player();
  if (who->GetSleeping())  return "You have a boring yet relaxing dream.";
  if (who->GetParalyzed()) return "You are paralyzed.";
  if (who->GetStaminaPoints() < 50) return "You are too tired.";
  if (who->GetInCombat()) return "This situation has come apart at the seams.";
  return 1;
}

mixed do_sew_str_from_obj_with_obj(string args, object mat1, object mat2) {
  int size_value = 0;
  string size_text = "medium";
  string garment = "";
  object who = this_player();
  
  debug("trying to get size info out");
  // pull out size information, if available
  foreach(string size in keys(Sizes)) {
    if(strsrch(args, size) == 0) {
      size_text = size;
      args = replace_string(args, size, "");
    }
  }
  debug("trying to determine garment");
  debug(args);

  // check for legal garment type
  if ( member_array(args, keys(Garments)) == -1) {
    who->eventPrint("You cannot sew a " + args + ".");
    who->eventPrint("You can only sew " + conjunction(keys(Garments)) + ".");
    return 0;
  }
  
  garment = args;
  who->AddStaminaPoints(-50);
  eventCraft(garment, size_text, ({mat1, mat2}), who);
  
  return 1;
}
