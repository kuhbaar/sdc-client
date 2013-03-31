A simple chat client using ZeroC Ice Middleware. Server only has one method - echo(string s) - which returns the string sent.
Client connects to given server, at given port and using the given certificate.

slice files will be automagically created by cmake.
Workflow: create build directory, execute "cmake .." and "make"