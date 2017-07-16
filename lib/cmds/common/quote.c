/*  Quote v2.0b
 */
#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;
inherit LIB_HELP;


mixed cmd(string args)
{
  string quote, author, who;

  who = capitalize(this_player()->GetKeyName());
  if (!args)
  {
    return QUOTES_D->eventDisplayQuote(this_player());
  }
  if (sscanf(args, "%s~%s", quote, author))
  {
    QUOTES_D->AddQuote(quote, author, who);
    message("system", "Quote added!", this_player());
    return 1;
  }
  return 0;
}


string GetHelp(string blah) {
  return  "Syntax:   <quote>\n"
          "          <quote [quote]~[author]\n\n"
          "Using <quote> by itself will return a random quote from the list. "
          "To add a new quote, use <quote> followed by the quote, then "
          "by a tilda (~) and the author's name. For example: \"quote Quote "
          "is the best command ever ~ Everyone\". Please use proper capitalization "
          "and make sure that quotes are in good taste. Note that the contributor's "
          "name is also logged and those displaying bad taste will be reprimanded.";
}
