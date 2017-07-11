/* Inheritable to control init() fear.
 * Used for demons, dragons, or other truly horrible 
 * things, like meatloaf in the fridge.
 * Duuk@Haven 11 May 1997
 */
#include <conditions.h>

private int ResistLevel, FearLength;
private string FearType;
varargs int CheckResistFear(object who, int Level, string Type);
void eventCauseFear(object victim, int Duration);
int SetResistLevel(int X);
int GetResistLevel();
int SetFearLength(int X);
int GetFearLength();

void init() { }

int eventEncounter(object who) {
  int Duration;
  if (!living(who)) return 0;
  Duration = CheckResistFear(who, ResistLevel, FearType);
  if (Duration) {
   eventCauseFear( who, Duration );
  } else {
    if (!creatorp(who))
      message("other_action",
        "You are not overly affected by the " + FearType + ".",
        who);
    }
  return Duration;
}

/* SetResistLevel(int X)
 * This is the player level where the player is no longer 
 * affected by the fear given off by the object.
 * Note that this should be defined even if it is not being 
 * used.  (See CheckResistFear)
 */

int SetResistLevel(int X) {
    return (ResistLevel = X);
  }

int GetResistLevel() {
   return (ResistLevel);
  }


/* int SetFearLength(int X)
 * Sets the duration of paralysis that is inflicted
 * upon the victim in the event of failure in CheckResistFear.
 */

int SetFearLength(int X) {
  return (FearLength = X);
   }

int GetFearLength() {
    return (FearLength);
   }

/* void eventCauseFear(object victim, int Time)
 * This is the function which actually imposes the fear
 * onto the target.  It sends a basic message along with
 * sets the paralysis.
 */

void eventCauseFear(object victim, int Time) {
   if (creatorp(victim)) { return; }
   send_messages("are", "$agent_name $agent_verb overwhelmed by the " + FearType + "!",
       victim, 0, environment(victim) );
    victim->AddCondition(FearType, CONDITION_PREVENT_MOVE|CONDITION_PREVENT_COMBAT|CONDITION_PREVENT_MAGIC|CONDITION_FEAR, Time);
  }


/* string SetFearType(string args) 
 * Sets the name of the fear which is imposed.
 * Note that if using default messages, the surrounding
 * syntax will always be 'overwhelmed by the <FearType>'
 */

string SetFearType(string args) {
  return (FearType = args);
  }

string GetFearType() {
    return (FearType);
   }

/* varargs int CheckResistFear(object who, int Level, string Type)
 * This is the primary function to determine if a target is affected
 * by the fear.   It is also the primary function that an creator
 * would want to override to make unique types of fear.  This function
 * simply takes a set number (SetResistLevel) and compares it to the
 * level of the player.  Other overrides of this function could be 
 * used as checking stats, equipment, etc.
 * This function returns (GetFearLength) if there is no override.
 */

/* 
 * varargs int CheckResistFear(object who, int Level, string Type){
     if (!living(who)) return 0;
 *   if (creatorp(who)) { return 0; }
 *     if (who->GetLevel() > Level) {
 *       return 0;
 *       }
 *     else {
 *       if (who->GetProperty("blessed")) {
 *          return 0;
 *         }
 *       }
 *   return (FearLength);
 *   }
 */

/*
 * New method to limit abuse of the "Bless" Spell
 */
   
varargs int CheckResistFear(object who, int lvl, string Type){
  if(creatorp(who)) {return 0;}
  if((who->GetLevel() * (who->GetProperty("blessed") ? 2:1)) > lvl) {
    return 0;
    }
  return (FearLength);
}
    
	
