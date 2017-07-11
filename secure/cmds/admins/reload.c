#include <commands.h>
#include <lib.h>
inherit LIB_DAEMON;
inherit LIB_HELP;

string cmd(string str) {
   string result = "Failed to update ";
  if (!str) { 
    return "What do you want to reload?";
    }
  switch (str) {
    case "intermud":
/*
      rm("/save/intermud.o");
*/
      CMD_UPDATE->cmd("/daemon/services/*");
      CMD_UPDATE->cmd("/daemon/services");
      CMD_UPDATE->cmd("/daemon/intermud");
      result = "Updated ";
      break;
    case "player":
      CMD_UPDATE->cmd("/lib/livings/*");
      CMD_UPDATE->cmd("/lib/livings/combat/*");
      CMD_UPDATE->cmd("/lib/livings/combat");
      CMD_UPDATE->cmd("/lib/livings/living");
      CMD_UPDATE->cmd("/lib/users/player -r");
      result = "Updated ";
      break;
    case "sefun":
    	CMD_UPDATE->cmd("/secure/sefun/*");
    	CMD_UPDATE->cmd("/secure/sefun/sefun");
    	result = "Reloaded ";
      break; 
    case "npc":
      CMD_UPDATE->cmd("/lib/npcs/npc -r");
      result = "Reloaded ";
      break; 
    }
  return result + str;
}

string GetHelp(string useless) {
  return "Syntax:  reload <thing>\n\n" +
         "Reloads a given defined series of objects.  This can "
         "be used to batch update common ideas.\n" +
         "Available batchs: intermud";
}
