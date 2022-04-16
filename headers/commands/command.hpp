#pragma once
#include "../structure/server.hpp"

namespace irc {
	class server;
	class command {
	/* Typedefs */
		private:
		public:
	/* Variables */
		private:
		protected:
			vector_string	_args;
		public:
	/* Constructors & Destructors */
		private:
			command(command const &src);
		public:
			command();
			command(vector_string const &args);
			virtual ~command();
	/* Operators */
		private:
			command& operator=(command const &src);
		public:
	/* Getters & Setters */
		private:
		public:
			vector_string const	&get_args() const;
			void				set_args(vector_string const &args);
	/* Functions */
		private:
		public:
			virtual void		is_valid_args(server const *server) const = 0;
			virtual void		exec_cmd(command const &cmd) const = 0;
	};
}
#include "../commands/invite.hpp"
#include "../commands/kick.hpp"
#include "../commands/mode.hpp"
