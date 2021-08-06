/*  Sew verb
 *  sews fabric from yarn
 *  Sews socks from fabric using thread
 */
#include <lib.h>
#include <std.h>
#include <daemons.h>
inherit LIB_VERB;

mapping Patterns = ([
	"checked" : ({1, "checkerboard"}),
	"chevron" : ({25, "alternating chevron"}),
	"fleur-de-lis" : ({50, "fleur-de-lis"}),
	"brocade" : ({100, "detailed floral"}),
	"chinoiserie" : ({200, "detailed scenic"}),
]);

static void create() {
  ::create();
  SetVerb("weave");
  SetRules("STR with OBJ");
  SetErrorMessage("Weave what pattern with what loom?");
  SetHelp("Syntax:   weave <pattern> with <loom>\n"
    "Attempts to weave the specific patterned fabric from yarn attached to a loom.\n"
    "Bolts of fabric are made from two spools of yarn.\n"
  );
}

int eventCraft(object loom, string pattern, object who) {
  object fabric = new(STD_CRAFTING + "clothing/fabric");
  string adj;
  object* materials = ({ });
  string* repair_skills = ({ });
  int lvl = 0;
  
  if (!fabric) {
    debug("Failed to create fabric");
    return -1;
  }

  // add the first two yarn found on the loom to our materials to use.
  foreach(object material in all_inventory(loom)) {
  	if (material->GetProperty("craft_yarn")) {
  	  materials += ({ material });
  	  // fail here if found yarn isn't going to work
      if (!material->GetMaterials() || !sizeof(material->GetMaterials()) ) {
        debug("Bad sewing mat: " + material->GetShort());
        return -1;		  
      }
  	  if (sizeof(materials) >= 2) break;
  	}
  }

  if (sizeof(materials) < 2) {
    who->eventPrint("There's not enough on the loom to weave fabric!");
    who->eventPrint("You must attach two yarns to the loom to weave.");
    return 0;
  }
  
  // Test our skills for each yarn.
  foreach(object material in materials) {
    // for each type of material in the material, test the player's relevant skill.
    foreach(string mat_type in material->GetMaterials() ){
  	  lvl += who->eventCheckSkill(mat_type + " working",10,who->GetLuck(),0);
  	  if(member_array(mat_type,repair_skills) == -1 ) {
  	  	repair_skills += ({mat_type});  
  	  }
    }
    lvl /= sizeof(material->GetMaterials());
  }
  lvl /= sizeof(materials);
  lvl /= 2; // skill #s are double player level #s.
  
  // failed the skill check.
  if (lvl < 1) {
  	 send_messages("ruin","$agent_name $agent_verb $target_name", 
  	 	 who, materials[0], environment(who));
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
  fabric->SetLevel(lvl);  
  send_messages( ({ "weave" }),
    "$agent_name " + adj + " $agent_verb "+materials[0]->GetShort()+" and " 
    + materials[1]->GetShort() + " into fabric.", 
    who, 0, environment(who));
  fabric->SetCraftMaterials(repair_skills);
  fabric->SetCraftSources( materials[0]->GetCraftSources() + materials[1]->GetCraftSources()  );
  fabric->SetCraftColors( materials[0]->GetCraftColors() + materials[1]->GetCraftColours() );
  fabric->SetCraftPattern(pattern);
  // eat up the materials used
  materials[1]->eventDestruct();
  materials[0]->eventDestruct();

  if (who->CanCarry(fabric->GetMass())) {
    fabric->eventMove(who);
  } else {
    fabric->eventMove(environment(who));
    who->eventPrint("The fabric is too heavy for you to carry right now.");
  }
  fabric->SetCraftedState();
}

mixed can_weave_str_with_obj() {
  object who = this_player();
  if (who->GetSleeping())  return "You have a boring yet relaxing dream.";
  if (who->GetParalyzed()) return "You are paralyzed.";
  if (who->GetStaminaPoints() < 50) return "You are too tired.";
  if (who->GetInCombat()) return "This situation has come apart at the seams.";
  return 1;
}

mixed do_weave_str_with_obj(string pattern, object loom ) {
  object who = this_player();
  if(member_array(pattern, keys(Patterns)) == -1 ) {
    who->eventPrint("Possible patterns are: " + implode(keys(Patterns)," "));
    return 1;
  }
  who->AddStaminaPoints(-50);
  
  eventCraft(loom, pattern, who);
  return 1;
}
