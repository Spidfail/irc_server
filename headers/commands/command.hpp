#pragma once
#include "../structure/Server.hpp"

namespace irc {
	class Server;
	class command {
	/* Typedefs */
		private:
		public:
	/* Variables */
		private:
		protected:
			vector_string	_args;
			Server			*_server;
		public:
	/* Constructors & Destructors */
		private:
			command(command const &src);
		public:
			command();
			command(Server *server);
			virtual ~command();
	/* Operators */
		private:
			command& operator=(command const &src);
		public:
	/* Getters */
		private:
		public:
			vector_string const	&get_args() const;
	/* Setters */
		private:
		public:
			void				set_args(vector_string const &args);
	/* Functions */
		private:
		public:
			virtual void		check_auth(const User &user);
			virtual bool		is_valid_args(User const &user) = 0;
			virtual void		exec_cmd(User &user) = 0;
	};
}
#include "../commands/invite.hpp"
#include "../commands/Kick.hpp"
#include "../commands/Mode.hpp"
#include "../commands/Join.hpp"
#include "../commands/Nick.hpp"
#include "../commands/Kick.hpp"
#include "../commands/Message.hpp"
#include "../commands/User_cmd.hpp"
#include "../commands/Cap.hpp"
#include "../commands/Pass.hpp"
#include "../commands/Ping.hpp"
#include "../commands/Pong.hpp"
#include "../commands/Notice.hpp"
#include "../commands/Part.hpp"
#include "../commands/Quit.hpp"
