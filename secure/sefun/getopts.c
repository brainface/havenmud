/*
 * LPC implementation of getopt() from C.  Doesn't actually work much like the
 * real thing.  Takes an argument line like "-chooc -l50 -g", and an array of
 * options to search for like ({ "-ch", "-l", "-g" }) and spits out a mapping
 * like ([ "-ch" : "ooc", "-l" : "50", "-g" : "" ]).  Note that all values are
 * strings.
 */

mapping getopts(string arg, string *list)
{
  mapping result = ([ ]);
  string *args = explode(arg, " ");

  foreach (string option in list)
  {
    foreach (string opt in args)
    {
      string tmp;
      if (sscanf(opt, sprintf("%s%%s", option), tmp))
      {
        result[option] = tmp;
        args -= ({ opt });
      }
    }
  }
  return result;
}
