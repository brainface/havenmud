#include <lib.h>
#include <magic.h>
#include <daemons.h>
#include <std.h>
inherit LIB_SPELL;

static void create() {
        spell::create();
        SetSpell("wind walk");
        SetRules("", "STR");
        SetSpellType(SPELL_OTHER);
        SetSkills( ([
           "natural magic" : 250,
           "enchantment" : 250,
                ]) );
        SetMagicCost(175, 175);
        SetDifficulty(180);
        SetGlobalSpell(1);
        SetHelp(
         "This spell allows a powerful druid to move themselves to a target by "
         "using the power of wind. "
         "Also if anyone is following the caster at the time of the teleportation "
         "they too are teleported. "
        );
}

varargs object *GetTargets(object who, mixed args...) {
  object targets;

  if(sizeof(args) < 1) {
     message("system", "Wind Walk to whom?", who);
     return 0;
     }
     targets = find_living(args[0]);
  if (!targets || targets->GetInvis()) {
     message("system", "Unable to find your target.", who);
    return 0;
     }
  if(!environment(targets)) {
     message("system", "Unable to locate your target.", who);
     return 0;
      }
  return ({ targets });
  }
  
varargs int CanCast(object who, int level, string limb, object array targets) {
        object target = targets[0];
        object env  = environment(who);
        object envT; 
        int distance;
        
        if( creatorp(target) || target->GetTestChar()) {
                message("fail", "Cast it on whom?", who);
                return 0;
                }
        if( environment(target)->GetProperty("no teleport") ) {
                message("fail", "You cannot wind walk to "   + target->GetName()+".", who);
                return 0;
                }
        if( environment(who)->GetProperty("no teleport") ) {
                message("fail", "You cannot wind walk from here.", who);
                return 0;
                }
        if( environment(target)->GetProperty("lower plane") ) {
                message("fail", "You cannot transport to "   + target->GetName()+".", who);
                return 0;
                }
        if( environment(who)->GetProperty("lower plane") ) {
                message("fail", "You cannot transport from here.", who);
                return 0;
                }
        if( environment(who) == environment(target) ) {
                message("fail", "But " + target->GetName() + " is already here.",       who);
                return 0;
                }        

        if (living(targets[0])) envT = environment(targets[0]);
            else envT = targets[0];
            distance = DISTANCE_D->GetDistance(env->GetDomain(), envT->GetDomain());
            SetDifficulty(50 * (1 + distance));
        return spell::CanCast(who, level, limb, targets);
}

varargs int eventCast(object who, int level, string limb, object array targets) {
  object target = targets[0];
  object* followers;
  followers = who->GetFollowers();
  if(!followers) followers = ({});
      who->eventMoveLiving(environment(target), "A gust of wind surrounds $N.", "$N appears from inside a small tornado.");
      followers->eventMoveLiving(environment(target), "A gust of wind surrounds $N.", "$N appears from inside a small tornado.");
    return 1;
  }

