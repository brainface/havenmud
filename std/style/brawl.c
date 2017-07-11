/*  Brawling */
#include <lib.h>
inherit LIB_COMBATSTYLE;

static void create() {
  ::create();
  SetStyleName("brawling");
  SetTrainingPointCost(16);
  SetSkills( ([
    "melee combat" : 5,
    ]) );
  SetStaminaCost(2);
  SetHelp("Typified by a random barroom brawl, this style of melee "
          "combat is one that involves punches, kicks, biting, swearing "
          "and otherwise being a rude and violent person.");
 }
int eventStyle(object who, int level, mixed target) {
  int dmg;
  string message;
  string verb;
  string limb;
  if (arrayp(target)) target = target[0];

  limb = target->GetRandomLimb();
  switch(dmg = random(level)) {
      case 0..5:
         verb = "punch";
          message = "bruising $target_objective lightly.";
          break;
      case 6..10:
           verb = "kick";
           message = "bruising $target_objective lightly.";
           break;
      case 11..20:
            verb = "bruise";
            message = "with a solid hit to the " + limb + ".";
            break;
      case 21..30:
            verb = "chop";
             message = "in the " + limb + ", severely hurting $target_objective!";
             break;
      case 31..40:
             verb = "pound";
             message = "squarely in the " + limb + " with a "
                       "wild attack!";
            break;
     case 41..50:
          verb = "wail";
          message = "firmly in the " + limb + ".";
           break;
    case 51..60:
       verb = "pummel";
       message = "resoundingly in the " + limb + ".";
      break;
    case 61..70:
        verb = "thump";
         if (target->GetLimbClass(limb) < 3) {
            message = "causing $target_objective to fall down!";
             target->eventCollapse();
           }
         else message = "causing a blinding wince of pain.";
        break;
    case 71..80:
         verb = "chop";
         message = "while yelling savagely for blood!";
         break;
     case 81..100:
          verb = "slam";
           limb = target->GetTorso();
          message = "knocking $target_objective to collapse!";
          target->eventCollapse();
          break;
    default:
        verb = "hit";
        message = ".";
        break;
  }

  dmg = who->GetDamage(dmg/3, "melee attack", target->GetDefense());
  send_messages(verb, "$agent_name $agent_verb $target_name " + message,
                who, target, environment(target) );
  target->eventReceiveDamage(who, who->GetMeleeDamageType(), dmg, 0, limb);
  who->eventTrainCombatStyle("brawling", dmg);
  return 1;
 }
