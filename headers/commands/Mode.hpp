#pragma once
#include "command.hpp"
#include <ratio>
#include <sys/_types/_size_t.h>

namespace irc {
	class Mode: public command {
	/* Typedefs */
		private:
		public:
	/* Nested Classes */
		private:
		public:
			// struct Channel {

			// };
			// struct User {

			// };
	/* Variables */
		private:
			std::string		_modes;
			std::string		_modes_args;
			char			_sign;

		public:
	/* Constructors & Destructors */
		private:
			Mode(Mode const &src);
		public:
			Mode();
			Mode(Server *server);
			virtual ~Mode();
	/* Operators */
		private:
			Mode &operator=(Mode const &src);
		public:
	/* Functions */
		private:
			void	_valid_chanMode(User const &author);
			void	_exec_chanMode(User const &author);
			void	_valid_userMode(User const &author);
			void	_exec_userMode(User const &author);
			bool	_is_valid_mode(string const &arg, string const &modes, string &pos) const;
			bool	_is_valid_flag_mode(string const &arg) const;
			bool 	_is_valid_arg_nb(string const &modes);
			void	_check_modes(string const &arg) const;

			void	_build_return_message(User const &authore);

			bool	_sign_handler(const char new_sign);

			// With args
			void	_channel_mode_o(Channel *channel, vector_string::const_iterator nickname,const User &author); // User
			void	_channel_mode_l(Channel *channel, vector_string::const_iterator nickname,const User &author); // limit -> ONLY  if (is_positive == true)
			void	_channel_mode_b(Channel *channel, vector_string::const_iterator arg,const User &author); // ban mask
			void	_channel_mode_k(Channel *channel, vector_string::const_iterator arg,const User &author); // channel key : password
			// Mute or not mute
			void	_channel_mode_v(Channel *channel, vector_string::const_iterator arg,const User &author);
			//
			//// No args
			void	_channel_mode_t(Channel *channel, vector_string::const_iterator arg,const User &author);
			void	_channel_mode_n(Channel *channel, vector_string::const_iterator arg,const User &author);
			void	_channel_mode_m(Channel *channel, vector_string::const_iterator arg,const User &author);
			//
			// // flag
			void	_channel_mode_p(Channel *channel, vector_string::const_iterator arg,const User &author);
			void	_channel_mode_s(Channel *channel, vector_string::const_iterator arg,const User &author);
			void	_channel_mode_i(Channel *channel, vector_string::const_iterator arg,const User &author);

			void	_user_mode_i(vector_string::const_iterator arg, const User &author);
			void	_user_mode_s(vector_string::const_iterator arg, const User &author);
			void	_user_mode_w(vector_string::const_iterator arg, const User &author);
			void	_user_mode_o(vector_string::const_iterator arg, const User &author);

		public:
			void	exec_cmd(User &user);
			bool	is_valid_args(User const &user);
	};
}
