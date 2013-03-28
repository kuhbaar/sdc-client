A simple chat client with few features.

slice2cpp --stream -I /usr/share/Ice-3.4.2/slice/ SecureDistributdChat.ice  //use to get a slice file

The server has an echo method, returning what client has sent. This Program connects to a given server using given port and sending "hello chat".