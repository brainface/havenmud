/* Created By Ohtar
*  2010
* Animalistic Protection
* Natural Evokation Timed Shield
*/

#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;
int ShieldStrike(object who, object agent, int x, class MagicProtection cl);
void endCallback(object who);

static void create() {
  spell::create();
  SetSpell("animalistic protection");
  SetRules("", "LIV");
  SetUniqueSpell(1);
  SetSpellType(SPELL_DEFENSE);
  SetShieldType(SHIELD_TIMED);
  SetProtectionTypes(ALL_EXTERNAL);
  SetSkills( ([     
    "natural magic" : 250,
    "evokation" : 250,
    ]) );
  SetDifficulty(200);
  SetHelp(
    "The animalistic protection spell is a blessing for all natural magic "
    "users. It gives them the ability to defend themselves against all "
    "types of damage. Calling on the strongest animals in the world to "
    "give them the strengths they possess to defend them for an extended " 
    "period of time."
    );    
  SetMessages( ({
        ({ "",  "$agent_possessive keen %^YELLOW%^BOLD%^animalistic instincts%^RESET%^ " 
                "run %^YELLOW%^wild%^RESET%^, forming a barrier of protection " 
                "around $target_name." }),
        }) );
           
 }

int hitCallback(object who, object agent, int dmg, class MagicProtection cl) {
  if (who == agent) return 0;  
  switch(random(3)) {
    case 0:
      send_messages("strike", "The %^YELLOW%^BOLD%^animalistic barrier"
          "%^RESET%^ around $agent_name %^BOLD%^WHITE%^suddenly blinks"
          "%^RESET%^ as $target_name $target_verb it!",
          who, agent, environment(who) );
      break;
    case 1:
        send_messages("assault", "The %^GREEN%^BOLD%^animalistic barrier"
          "%^RESET%^ around $agent_name %^RED%^surges repeatedly"
          "%^RESET%^ as $target_name $target_verb it!",
          who, agent, environment(who) );
      break;
    case 2:
      send_messages("assault", "The %^BLUE%^BOLD%^animalistic barrier "
          "%^RESET%^around $agent_name %^WHITE%^fades slightly%^RESET%^ "
          "as $target_name $target_verb it!",
          who, agent, environment(who) );
      break;
    }
  return dmg;
  }

void endCallback(object who) {
    if( who ) {
      send_messages("", "The %^BOLD%^CYAN%^animalistic barrier%^RESET%^ "
        "around $agent_name flickers brightly before vanishing into thin "
        "air.",
        who, 0, environment(who));
    }
}

