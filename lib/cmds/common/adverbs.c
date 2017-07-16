/*
 * adverbs.c
 * Gives a comma-delimited list of all adverbs
 * Created by Zaxan@Haven
 */

#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;

int filter_test(string adverb, string prefilter)
{
   if(adverb[0..strlen(prefilter)-1] == prefilter)
      return 1;
   return 0;
}

mixed cmd(string arg)
{
   string array adverbs = sort_array(ADVERBS_D->GetAdverbs(), 0);

   if(arg) adverbs = filter(adverbs, (: filter_test :), arg);

   if(!sizeof(adverbs)) return "No adverbs satisfy your filter.";
   
   return implode(adverbs, ", ");
}

string GetHelp()
{
   return ("Syntax: <adverbs>\n"
           "        <adverbs [pre-filter]>\n\n"
           "Without argument, will return a comma-delimited list of all adverbs "
           "available. If a pre-filter is provided, the list is restricted to "
           "adverbs that start with that filter.");
}

