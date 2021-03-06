#include "../../headers/commands/User_cmd.hpp"

namespace irc {
/* Constructors & Destructors */
	User_cmd::~User_cmd() {};
	User_cmd::User_cmd(){};
	User_cmd::User_cmd(Server *server): command(server) {};
/* Operators */
/* Functions */
	void User_cmd::send_connection_rpl(User &user) {
		string ret;
		ret = ":" + user.get_server()->get_name() + " 001 " +user.get_nickname() + " :" + "Welcome to our 42Lyon IRC network " + user.get_nickname() + "!" + user.get_username() + "@" + user.get_hostname() + "\n"
			+ ":" + user.get_server()->get_name() + " 002 " + user.get_nickname() + " :" + "Your host is " + user.get_server()->get_name() + ", running version 1.0 " + "\n"
			+ ":" + user.get_server()->get_name() + " 003 " + user.get_nickname() + " :" + "This server was created 00:20:08 Apr 21 2022\n"
			+ ":" + user.get_server()->get_name() + " 004 " + user.get_nickname() + " " + user.get_server()->get_name() + " 1.0 BDHILRSTWcdghikorswxz ABCDEFIJKLMNOPQRSTUWXYZbcdefhijklmnoprstuvwz BEFIJLWXYZbdefhjklovw\r\n";
		Proxy_queue::Write * msg = new Proxy_queue::Write(user.get_socket()->get_fd(),ret.c_str());
		ret = ":" + user.get_server()->get_name() + " NOTICE " + user.get_nickname() + " :Authors: mhaman guhernan lwourms\n"
			+ ":" + user.get_server()->get_name() + " NOTICE " + user.get_nickname() + " :Available Commands: PRIVMSG JOIN MODE KICK INVITE USER NICK NOTICE PART QUIT PING PONG\n"
			+ ":" + user.get_server()->get_name() + " NOTICE " + user.get_nickname() + " :Available Service: Help_Bot Usage NOTICE Help_bot COMMAND\r\n";
		Proxy_queue::Write * notice = new Proxy_queue::Write(user.get_socket()->get_fd(),ret.c_str());

		_server->get_event_list().push_back(msg);
		_server->get_event_list().push_back(notice);
	}

	void User_cmd::exec_cmd(User &user) {
		user.set_username(_args[1]);
		user.set_hostname(_args[3]);
		user.set_realname(_args[4]);
		if (user.get_registered_status() == false and !user.get_nickname().empty())
		{
			user.set_registered_status(true);
			user.set_uuid();
			send_connection_rpl(user);
		}
	};

	// Server is unused here.
	bool User_cmd::is_valid_args(User const &user) {
		if (this->_args.size() < 5)
			throw error(this->_args[0] + ": Not enough parameters", ERR_NEEDMOREPARAMS);
		if (user.get_registered_status() == true)
			throw error(" You're already registered", ERR_ALREADYREGISTRED);
		for (std::string::const_iterator it = _args[1].begin(); it != _args[1].end(); ++it)
			if ((*it) == 0 or (*it) == 10  or (*it) == 13 or (*it) == 64 or (*it) == 32)
				throw error("Invalid username", ERR_ERRONEUSNICKNAME);
				// WIP verfication du hostname a faire
		for (string::const_iterator it = _args[4].begin(); it != _args[4].end(); ++it)
			if ((*it) == 0 or (*it) == 10  or (*it) == 13 or (*it) == 64)
				throw error("Invalid realname", ERR_ERRONEUSNICKNAME);
		return true;
	};
}
