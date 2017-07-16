
/*  Damn arachnicide
 */

#include <lib.h>
#include <rooms.h>

inherit LIB_HELP;
//inherit LIB_DAEMON;

mixed cmd(string args)
{
  object target;
  object spider;
  int i;
  if (this_player()->GetKeyName() != "mahkefel")
    return "The spiders don't obey you!"; 
  if (!args)
      return "The spiders don't understand that!";
  if (!(target = find_player(args)))
      return "Even the spiders can't find that!";  
  // *whistles innocently*
  if (!creatorp(target))
    return "The spiders know that's a horrible idea!";

  for(i=0;i<100;i++) {
    spider = new("/realms/mahkefel/npc/spider");
    if(!spider) return "This spiders have failed us!";
    spider->eventMove(environment(target));
  }

  this_player()->eventPrint("The spiders heed your call!");
  return 1;
}

string GetHelp()
{
  return "Syntax :  <arachnicide [player]>  \n\n"
         "On our world it's considered a greater crime \n"
         "to unleash killer spiders on an unarmed crowd.\n"
         "We call that arachnicide.";
}

