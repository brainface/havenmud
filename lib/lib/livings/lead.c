/*    From the Dead Soulsr2 Object Library
 *    Provides lead support for mobile objects.
 *    Works closely with LIB_FOLLOW.
 *    Created by Rush 951028
 */

#include <lib.h>
#include "include/lead.h"

private static mapping Followers;

static void create() {
  Followers = ([]);
}

mixed direct_lead_liv() {
    if( this_object() == this_player() ) return "That's silly.";
    return this_player()->CanLead();
}

mixed direct_evade_liv() {
    if( this_object() == this_player() ) return "That's silly.";
    return this_player()->CanEvade(this_object());
}

object *AddFollower(object follower) {
    class FollowerClass tmp;

    if( !objectp(follower) ) error("Bad argument 1 to AddFollower().\n");
    if (sizeof(GetFollowers()) >= 5) return GetFollowers();
    if( follower != this_object() && !Followers[follower]
      && !follower->GetProperty("no follow") ) {
        if( !follower->IsFollowing(this_object()) ) {
            if( follower->SetLeader(this_object()) ) {
                tmp = new(class FollowerClass);
                tmp->allowed = 0;
                tmp->bonus = 0;
                tmp->lost = 0;
                Followers[follower] = tmp;
            }
        }
    }
    return GetFollowers();
}

object *RemoveFollower(object follower) {
    if( !objectp(follower) ) error("Bad argument 1 to RemoveFollower().\n");
    map_delete(Followers, follower);
    follower->SetLeader(0);
    return GetFollowers();
}

object *GetFollowers() { return filter(keys(Followers), (: $1 :)); }

int SetAllowed(object follower, int allowed) {
    if( !objectp(follower) ) error("Bad argument 1 to SetAllowed().\n");
    if( !intp(allowed) ) error("Bad argument 2 to SetAllowed().\n");
    if( !Followers[follower] ) return 0;
    return(((class FollowerClass)Followers[follower])->allowed = allowed);
}

int GetAllowed(object follower) {
    if( !objectp(follower) ) error("Bad argument 1 to GetFollowBonus().\n");
    if( !Followers[follower] ) return 0;
    return ((class FollowerClass)Followers[follower])->allowed;
}

int AddFollowBonus(object follower, int bonus) {
    if( !objectp(follower) ) error("Bad argument 1 to AddFollowBonus().\n");
    if( !intp(bonus) ) error("Bad argument 2 to AddFollowBonus().\n");
    if( !Followers[follower] ) return 0;
    return( ((class FollowerClass)Followers[follower])->bonus += bonus );
}

int GetFollowBonus(object follower) {
    if( !objectp(follower) ) error("Bad argument 1 to GetFollowBonus().\n");
    if( !Followers[follower] ) return 0;
    return ((class FollowerClass)Followers[follower])->bonus;
}

varargs mixed CanLead(object ob) {
    if( ob ) {
        if( !ob->CanFollow() )
            return "You are not empowered to lead " + ob->GetName();
        if( ob->IsFollowing(this_object()) )
            return "You are already leading " + ob->GetName();
        if( this_object()->IsFollowing(ob) )
            return ob->GetName() + " is already leading you.";
        if( ob == this_object() )
            return "You cannot possibly do that.";
        // fail to lead if it's a horse dragging a wagon.
        if ( ob->GetHitcher() ) {
            return "Mounts hitched to wagons must be driven, not lead";
        }
    }
    return 1;
}

varargs mixed CanEvade(object ob) {
    if( ob && !ob->IsFollowing(this_object()) )
        return ob->GetName() + " is not following you.";
    return 1;
}

//mahk 2019: oh my god what does any of this mean
// what kind of nonsense is this these are not words
// oh my god why is there a followerclass

int eventMoveFollowers(object dest) {
    class FollowerClass follower;
    object ob;
    int followChance;

    foreach(ob in GetFollowers()) {
        follower = Followers[ob];
        followChance = 100;
        if( !follower->allowed ) followChance -= 20 + this_object()->GetSkillLevel("stealth");
        followChance += ob->GetSkillLevel("stealth");
        followChance += follower->bonus;
        if( ob->eventFollow(dest, followChance) ) follower->lost = 0;
        else if( follower->lost++ && eventEvade(ob) ) RemoveFollower(ob);
    }
    return 1;
}

int eventEvade(object ob) {
    mixed ret;

    ret = CanEvade(ob);
    if( stringp(ret) ) error(ret);
    if( ret = 1 ) {
        ob->eventPrint(this_object()->GetName() + " has evaded you.");
        this_object()->eventPrint("You have evaded " + ob->GetName() + ".");
        return 1;
    }
    return 0;
}


