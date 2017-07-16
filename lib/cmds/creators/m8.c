// The Magic 8 Ball
// From: Zeddicus@Haven

#include <lib.h>

inherit LIB_DAEMON;

string *phrases = ({
  "Yes.",
  "No.",
  "Outlook not so good.",
  "Definitely not!",
  "It is doubtful.",
  "Of course.",
  "Certainly!",
  "All signs point to YES!",
  "Can not predict now.",
  "Maybe.  Yes, I know you wanted a definitive answer, but what did you "
    "expect?  I'm a fucking 8ball command."
});

int cmd(string str)
{
  if (!str || (strsrch(str, "?", -1) != (strlen(str)-1)))
  {
    this_player()->eventPrint("I didn't hear your question. Questions from "
                              "smart people come through loud and clear. When "
                              "I tried to read your thoughts to understand "
                              "your question all I got was something that "
                              "sounded like gas.");
    return 1;
  }
  this_player()->eventPrint(phrases[random(sizeof(phrases))]);
  return 1;
}

string GetHelp()
{
    return "Syntax:  <m8 [question]>\n\n"
           "It's a magic 8-ball.  Ask it a question.";
}
