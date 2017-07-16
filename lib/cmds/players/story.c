/* story.c command */
#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

mixed cmd(string args) {
        object who = this_player();
        
        if (playerp(who)) {
                if (who->GetApprovedStory()) {
                        return who->GetStory();
                  }
    if (!args) {
        if (!who->GetStory()) return "You have no story.";
      
      return "Your current story is:\n" + who->GetStory();
    }
    CHAT_D->eventSendChannel("STORY", "reports", 
    capitalize(who->GetKeyName()) + " has set " + possessive(who) + " story to: " + args);
    return who->SetStory(args);
  }
  
  if (!args) { return "Show story for who?"; }
  
  if (!who = find_player(args)) {
        return "No such player.";
  }
  this_player()->eventPrint(who->GetStory() || "No story for that person.");
  return 1;
}

string GetHelp(string useless) {
        string tmp =
               "Syntax:  story \n"
               "         story <story>\n\n"
               "By using this command without arguments, you will be able to see your "
               "current character story. Using it with a story will set your story to "
               "that UNLESS your story has been approved already.  This character story "
               "is vital roleplaying information on your character. It shows the staff "
               "that you have thought your character out a bit, and put some ideas into "
               "this character. Please include some basic character history and how this "
               "character thinks.  Enjoy.\n\n"
            "Example Story: (courtesy of Yadda/Eric):\n"
         "Yadda Banewulf, Citizen of Haven Town, is the youngest son of Faolyn Banewulf, "
         "the younger brother of Annax Banewulf, Mayor of Haven.  Yadda's family is the "
         "lesser-known of the Banewulfs, and his family status gives him no special "
         "priviledges within the Town.  Yadda entered the barracks and signed up to be a "
         "simple warrior, hoping to one day prove that even one of Faolyn's sons could "
         "one day rise to be a Lord Commander of the Haven Town Guard. \n\n"
         
         "Example Story: (Netanyahu Haseraphim - Dark-elf Priest):\n"
           "Born a child of wealth and privilege, Netanyahu Haseraphim experienced much that"
           " life in Malveillant had to offer. After reaching maturity; however, Netanyahu"
           " manifested a sado-masochistic sexual urge that resulted in much scandal and"
           " not a few missing persons. With a mix of concern and adoration, Netanyahu's"
           " parents demanded he be indoctinated in the services of Alessandra."
           " Under the tutelage of Tallia, Netanyahu's passion was harnessed into great"
           " spiritual power. Armed with this power, and a thirst to please his Mistress,"
           " Netanyahu joined the ranks of the Priests of Alessandra to further the"
           " philosophy of self-gratification.\n\n"
       "Example #3: (Anie/Josh)"
          "\nAnie Wavecreast is the daughter of the terrifing pirate Captain Jacob \"Deadeye\" \n"
          "\nWavecrest. Her mother, the charming Alsea Sailstorm, drowned in the Endless Sea "         
          "\nafter falling overboard on her husbands ship. Distraught from the loss of his "           
          "\nwife, he abandoned his daughter Anie off at the Shrine in Parva when she was "            
          "\njust a baby. While living in the shrine, when Anie was barely a year old she "            
          "\nmet the half-elf Erel Wavecrest. They were both shocked to find that they "              
          "\nshared the same father, and have protected eachother from harm ever since."               
               ;
  if (creatorp(this_player())) { tmp +=
         "\n\nImmortal Syntax:     story <player>\n"
         "This command usage shows the story for a player.";
        }
  return tmp;
}
