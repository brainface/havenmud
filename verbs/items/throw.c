/* Throw verb
 * 11/7/2007
 * Duuk
 */
#include <lib.h>
#include <damage_types.h>
#include <rounds.h>

inherit LIB_VERB;

mixed do_throw_obj_at_obj(object what, object where);
int eventThrow(object who, object what, object where);

static void create() {
    verb::create();
    SetVerb("throw");
    SetRules("OBJ", "OBJ at OBJ");
    SetErrorMessage("Throw what?");
    SetHelp(
      "Syntax: <throw OBJ>\n"
	    "        <throw OBJ at OBJ>\n"
	    "\n"
	    "Allows you to throw an object.  \n"
	    "This is a COMBAT VERB.  Use <give> to hand something over.  Use "
	    "<throw> when you want to whip something at somebody to hurt them."
	  );
}

mixed can_throw_obj() {
   if (this_player()->GetSleeping()  ) return "You cannot do that while sleeping!";
   if (this_player()->GetParalyzed() ) return "You cannot do anything.";
   return 1;
}

mixed can_throw_obj_at_obj() {
    return can_throw_obj();
}

mixed do_throw_obj(object ob) {
  object target = this_player()->GetCurrentEnemy();
  if (!target) {
    this_player()->eventPrint("But you have no current enemy at which to throw " + ob->GetShort() + "!");
    return 1;
  } 
  return do_throw_obj_at_obj(ob, target);
}

mixed do_throw_obj_at_obj(object what, object target) {
   this_player()->eventPrint("You prepare to throw " + (string)what->GetShort() + ".");
   this_player()->SetAttack(target, (: eventThrow, this_player(), what, target :), ROUND_WEAPON );
   return 1;
}

int eventThrow(object who, object weapon, object target) {
  int pro, con, power;
  string limb = target->GetRandomLimb(target->GetTorso());
   
  send_messages( ({ "throw" }), "$agent_name $agent_verb " + weapon->GetShort() + " at $target_name!",  who, target, environment(target) );
  
  pro = who->GetWeaponChance(target, "projectile", 1, 1);
  con = target->GetStatLevel("agility")/10;
  con += target->GetLuck();
  con += target->GetDefense();


  pro = random(pro);
  con = random(con);
  weapon->eventMove(environment(who));
  if (con > (pro * 2)) { /* They beat me 2 to 1.  I suck. */
    who->SendCombatMessages(target, -2, weapon, limb);
    return 1;
    }
  if (!target->eventReceiveAttack(pro, "projectile", who, con)) {
    /* Returns a 0 meaning they beat me badly */
    who->SendCombatMessages(target, -1, weapon, limb);
    return 1;
    }
  /* I hit you, but how hard? */
  power = (weapon->eventStrike(target));
  power = who->GetDamage(power *8, "projectile combat", target->GetDefense());
  power = target->eventReceiveDamage(who, weapon->GetDamageType(), power, 0, limb);
  
  who->SendCombatMessages(target, power, weapon, limb);
  weapon->eventReceiveDamage(who, BLUNT, power/20, 0, limb);
  if (target->GetDying()) {
      who->eventPrint("You slay " + target->GetName() + " without mercy.");
      target->eventPrint(who->GetCapName() + " kills you.  You die.");
      environment(who)->eventPrint(who->GetCapName() + " kills " + target->GetCapName() + ".", ({ who, target }) );
      }
   return 1;   
}
