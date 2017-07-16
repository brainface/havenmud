contsorciere

//
// Sanctify Spell
// Coded by Dunedain@Haven
// 14 September 1997
//
 
#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

int EndShield();
 
static void create() {
  spell::create();
  SetSpell("create contsorciere aura");
  SetRules("");
  SetSkills( ([
                "divination"  : 4,
                "faith"       : 17,
                "enchantment" : 17,
           ]) );
  SetDifficulty(35);
  SetRequiredMagic(50);
  SetMagicCost(40,10);
  SetSpellType(SPELL_OTHER);
  SetHelp("Syntax: <cast create contsorciere aura>\n\n"
          "This spell, if successful, puts a damper on the magic in the "
          "area surrounding the caster.  The length of the aura "
          "depends on the skill of the caster.");
}
 
varargs int eventCast(object who, int level, string limb, object *targets) {
   object env = environment(who);
   if(env->GetProperty("no magic")) {
      message("other","This room is already protected against magic!",
              who);
      return;
   }
   send_messages(
}
 
int SanctifyRoom(object who) {
  int timelength;
  mapping savedproperties = ([]);
  if (!environment(who)->GetProperty("sanctified"))
  {
    timelength = (random(15) + (who->GetSkillLevel("faith")
                                    + who->GetSkillLevel("divination") ) / 2 );
