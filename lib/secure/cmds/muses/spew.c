#include <lib.h>

inherit LIB_DAEMON;

mixed cmd(string str) {
  string *arr;
  string tmp;
  int x,y;

  x = 1;

  if( !str ) return "You must specify a file to spew.";
  else str = absolute_path((string)this_player()->query_cwd(), str);
  if( !unguarded((:file_exists,str:)) )
    return "File " + str + " not found.";

  if (!securep(this_player()) &&
     (strsrch(str, "domains") == -1) &&
     (strsrch(str, "realms") == -1) &&
     (strsrch(str, "doc") == -1) &&
     (strsrch(str, "log") == -1) )
  unguarded( (: log_file,
    "adm/more",
     query_privs(this_player()) + " " + str + " \n" :) );

  if ( file_size(str) == 0)
    return "The file is empty.";
  
  while(tmp = unguarded( (: read_file,str,x,1 :) ))
  {
  y=(sizeof(arr=explode(tmp, "")));
  tmp = implode(arr[0..(y-2)],"");
  message("system",tmp,this_player());
  x++;
  }

  if(!x)
  {
  return "Unable to read file " + str + ".";
  }
  else
  {
  return 1;
  }
}

int help() {
  message("help", "Syntax: <spew [file]>\n\n"
    "Displays the contents of the file mentioned all at once.",
    this_player());
}

