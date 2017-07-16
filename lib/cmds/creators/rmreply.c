/*
 * rmreply cmd
 * Takes away a player's reply property
 * 
 * Written by Zaxan@Haven
 */

#include <lib.h>

inherit LIB_DAEMON;

int cmd(string str) {
    string reply;
    object target;

    if (!str)
    {
        this_player()->eventPrint("Who?");
        return 1;
    }

    target = find_living(str);

    if (!target || undefinedp(target))
    {
        this_player()->eventPrint("Could not find "+str+".");
        return 1;
    }

    if (creatorp(target))
    {
        this_player()->eventPrint("No.");
        return 1;
    }

    reply = target->GetProperty("reply");

    if (!reply)
    {
        this_player()->eventPrint("That player doesn't have anyone to reply to.");
        return 1;
    }
    
    if ((lower_case(reply) != lower_case(this_player()->GetKeyName())) &&
            !archp(this_player()))
    {
        this_player()->eventPrint("You're not who that player is replying to.");
        return 1;
    }

    target->RemoveProperty("reply");
    this_player()->eventPrint("Reply property removed.");

    return 1;
}

string GetHelp() {
    return ("Syntax: rmreply <player>\n\n"
            "Removes the reply property from a player so they can no longer reply "
            "back to you. This only works on a player and you must be the person "
            "the player is replying to (unless you're an arch).");
}
