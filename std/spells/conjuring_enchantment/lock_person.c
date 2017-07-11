/*  Allows a target to be locked into the caster's mind.
 */
#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() 
{
  spell::create();
  SetSpell("lock person");
  SetDifficulty(50);
  SetRules("LIV", "STR");
  SetGlobalSpell(1);
  SetRequiredMagic(90);
  SetMagicCost(100, 100);
  SetSpellType(SPELL_OTHER);
  SetSkills( ([
     "conjuring" : 215,
     "enchantment" : 215,
  ]) );
  SetHelp("Sets a teleport target to a person, rather than area destination. However "
          "teleporting long distances gets increasingly difficult with the increase "
          "of distance.");
}

varargs int eventCast(object who, int level, mixed n, object *t) 
{
  if (creatorp(t[0]) || who == t[0] || t[0]->GetTestChar() ) 
  {
    message("system", "Cast it on whom?", who);
    return 0;
  }
  message("system", "You get a clear image of " + t[0]->GetShort() +
    " in your mind.", who);
  message("other_action", "You get the odd feeling that someone is "
    "thinking of you.", t[0]);
  who->SetProperty("locked_target", base_name(t[0]));
  return 1;
}
