The aim of this folder is to write network programming programs like server and clients using sockets.
1. Wrote a simple server, client and demonstrated the use of apis like socket(), bind(), listen(), accept(), connect(). - Done
2. Modified the server to spawn a thread to handle the connection whenever a new client is connected. - Done
    Used client_run.sh shell script to run 1000's of client connections to server
    Monitored the increase in memory usage of the server process using "top -p <PID>" command
3. Update the multithreaded server to send a text file on request from the client. - Pending
4. Modify the server to use the select() system call instead of spawing the thread for each client connection. - Pending