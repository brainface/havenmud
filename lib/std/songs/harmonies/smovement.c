#include <lib.h>
#include <music.h>
#include <daemons.h>
#include <std.h>
inherit LIB_SONG;

static void create() {
        song::create();
        SetSong("sonic movement");
        SetRules("", "STR");
        SetSongType(SONG_OTHER);
       SetUniqueSong(1);
        SetSkills( ([
              "vocal music" : 300,
              "instrumental music" : 300,
                ]) );
        SetMagicCost(175, 175);
        SetDifficulty(180);
        SetGlobalSong(1);
        SetHelp(
                "This song allows the bard to move at the speed of sound and "
                "move themself as well as their companions directly to a target."
          );
}
  
varargs int CanSing(object who, int level, string limb, object array targets) {
        object target = targets[0];
        object env  = environment(who);
        object envT; 
        int distance;

        if( creatorp(target) || target->GetTestChar() || target->GetInvis()) {
                message("fail", "Sing to whom?", who);
                return 0;
                }

        if( environment(target)->GetProperty("lower plane") ) {
                message("fail", "You cannot sing to "   + target->GetName()+".", who);
                return 0;
                }
        if( environment(who)->GetProperty("lower plane") ) {
                message("fail", "You sing sonic movement here.", who);
                return 0;
                }
        if( environment(target)->GetProperty("no teleport") ) {
                message("fail", "You cannot sing to " + target->GetName()+".", who);
                return 0;
                }
        if( environment(who)->GetProperty("no teleport") ) {
                message("fail", "You cannot move away from here.", who);
                return 0;
                }
        if( environment(who) == environment(target) ) {
                message("fail", "But " + target->GetName() + " is already here.", who);
                return 0;
                }
        if (living(targets[0])) envT = environment(targets[0]);
            else envT = targets[0];
            distance = DISTANCE_D->GetDistance(env->GetDomain(), envT->GetDomain());
            SetDifficulty(50 * (1 + distance));
        return song::CanSing(who, level, limb, targets);
}

varargs int eventSing(object who, int level, string limb, object array targets) {
  object target = targets[0];
  object* followers;
  followers = who->GetFollowers();
  if(!followers) followers = ({});
      who->eventMoveLiving(environment(target), "$N fades into sound.", "$N appears in a magnificent boom.");
      followers->eventMoveLiving(environment(target), "$N fades into sound.", "$N appears in a magnificent boom.");
    return 1;
  }


