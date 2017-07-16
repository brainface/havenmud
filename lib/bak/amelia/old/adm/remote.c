/*    /lib/remote.c
 *    from the Nightmare IVr1 Object Library
 *    handles security for cre access via the remote creator protocol
 *    created by Descartes of Borg 950505
 *    modified by Dunedain ( Vivake Gupta ) 25 July 1998
 *      * improved security
 *      * corrected silly mistakes
 *      * made changes to work with RemoteEditor II while maintaining backwards
 *        compatibility
 */

#include <lib.h>

inherit LIB_DAEMON;

private static string Directory, Home;

protected void create()
{
  ::create();
  SetNoClean(1);
  Directory = Home = "/" +
    implode(explode(file_name(this_object()), "/")[0..<3], "/");
  if( strsrch(Directory, REALMS_DIRS) ) call_out( (: Destruct :), 0 );
}

string eventWriteFile(string file, string str)
{
  if( base_name(this_object()) == LIB_REMOTE )
    return "50 Failed to write file: " + file;
  if( file_size(file) > -1 && !rm(file) )
    return "50 Failed to write file: " + file;
  if( catch(write_file(file, str)) )
    return "50 Failed to write file: " + file;
  else
  {
    write_file("/log/edits/remote", explode(file_name(this_object()),"/")[1] +
                       " wrote " + file + " at " + ctime(time())+"\n");
    return "110 File " + file + " written.";
  }
}

string eventReadFile(string file)
{
  string tmp;

  if( base_name(this_object()) == LIB_REMOTE ) return "";
  file = absolute_path(Directory, file);
  if( !(tmp = read_file(file)) ) return "";
  else
  {
    write_file("/log/edits/remote", explode(file_name(this_object()),"/")[1] +
                       " read " + file + " at " + ctime(time())+"\n");
    return tmp;
  }
}

string GetAccess(string arg)
{
  string acc;

  if (master()->valid_read(arg,this_object(),"read_file") == 1) acc = "r";
  else acc = "-";
  if (master()->valid_write(arg,this_object()) == 1) acc += "w";
  else acc += "-";
  return acc;
}

string Filter(string dir, mixed array arg)
{
  string s;

  if (dir != "/") s = dir + "/" + (string)arg[0];
  else s = "/" + (string)arg[0];
  if (file_size(s) == -1) return "";
  return sprintf("%s\t%d\t%d\t%s",
                 GetAccess(s),(int)arg[1],(int)arg[2],(string)arg[0]);
}

string eventCommand(string cmd, string arg)
{
  string *files;
  object ob;
  string tmp;

  if( base_name(this_object()) == LIB_REMOTE ) return 0;
  switch(cmd)
  {
    case "ls":
      if( !arg || arg == "" ) arg = Directory;
      else if ( (arg != "/") && (arg[<1] == '/') ) arg = arg[0..<2];
      arg = absolute_path(Directory, arg);
      switch(file_size(arg))
      {
        case -2:
          if( arg[<1] != '/' ) arg += "/";
          files = ({ arg });
          files += map(get_dir(arg,-1), (: Filter($(arg), $1) :));
          return implode(files, "\t");
        case -1:
          return 0;
        default:
        {
          mixed stats = stat(arg);

          return sprintf("%s\t%d\t%d\t%s",
                          GetAccess(arg),stats[1],stats[0],arg);
        }
      }
    case "mkdir":
      arg = absolute_path(Directory, arg);
      if( file_size(arg) != -1 ) return 0;
      if( !mkdir(arg) ) return 0;
      else return "Directory created.";
    case "cd":
      arg = absolute_path(Directory, arg);
      if( !arg || arg == "" ) Directory = Home;
      else if( !((int)master()->valid_read(arg, this_object(), "cd")) )
        return 0;
      else Directory = arg;
      return Directory;
    case "rm":
      arg = absolute_path(Directory, arg);
      if( !rm(arg) ) return 0;
      write_file("/log/edits/remote", explode(file_name(this_object()),"/")[1] +
                         " rm'd " + arg + " at " + ctime(time())+"\n");
      return arg + " deleted.";
    case "rmdir":
      arg = absolute_path(Directory, arg);
      if( !rmdir(arg) ) return 0;
      else return arg + " deleted.";
    case "mv":
      files = explode(arg, " ");
      if( sizeof(files) != 2 ) return 0;
      files[0] = absolute_path(Directory, files[0]);
      files[1] = absolute_path(Directory, files[1]);
      if( catch(rename(files[0], files[1])) ) return 0;
      write_file("/log/edits/remote", explode(file_name(this_object()),"/")[1] +
                         " mv'd " + files[0] + " to " + files[1] + 
                         " at " + ctime(time())+"\n");
      return files[0] + " renamed to " + files[1] + ".";
    case "update":
      arg = absolute_path(Directory, arg);
      if( arg[<2..] == ".c" ) arg = arg[0..<3];
      if( ob = find_object(arg) )
      {
        if( !((int)ob->eventDestruct()) )
        return "Failed to destruct original object.";
      }
      if( tmp )
        return "Error in loading object: " + replace_string(tmp, "\n", "\t");
        else return arg + ": successfully loaded.";
  }
  return 0;
}
