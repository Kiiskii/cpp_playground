#pragma once

#ifndef ANSI_COLORS_HPP
# define ANSI_COLORS_HPP

// Basic
# define C_BL        "\033[0;30m\001"
# define C_R        "\033[0;31m\001"
# define C_G        "\033[0;32m\001"
# define C_Y        "\033[0;33m\001"
# define C_B        "\033[0;34m\001"
# define C_P        "\033[0;35m\001"
# define C_C        "\033[0;36m\001"
# define C_W        "\033[0;37m\001"

// Bold
# define C_B_BL        "\033[1;30m\001"
# define C_B_R        "\033[1;31m\001"
# define C_B_G        "\033[1;32m\001"
# define C_B_Y        "\033[1;33m\001"
# define C_B_B        "\033[1;34m\001"
# define C_B_P        "\033[1;35m\001"
# define C_B_C        "\033[1;36m\001"
# define C_B_W        "\033[1;37m\001"

// Underline
# define C_U_BL        "\033[4;30m\001"
# define C_U_R        "\033[4;31m\001"
# define C_U_G        "\033[4;32m\001"
# define C_U_Y        "\033[4;33m\001"
# define C_U_B        "\033[4;34m\001"
# define C_U_P        "\033[4;35m\001"
# define C_U_C        "\033[4;36m\001"
# define C_U_W        "\033[4;37m\001"

// Background
# define C_BG_BL    "\033[40m\001"
# define C_BG_R        "\033[41m\001"
# define C_BG_G        "\033[42m\001"
# define C_BG_Y        "\033[43m\001"
# define C_BG_B        "\033[44m\001"
# define C_BG_P        "\033[45m\001"
# define C_BG_C        "\033[46m\001"
# define C_BG_W        "\033[47m\001"

// High intensity
# define C_HI_BL    "\033[0;90m\001"
# define C_HI_R        "\033[0;91m\001"
# define C_HI_G        "\033[0;92m\001"
# define C_HI_Y        "\033[0;93m\001"
# define C_HI_B        "\033[0;94m\001"
# define C_HI_P        "\033[0;95m\001"
# define C_HI_C        "\033[0;96m\001"
# define C_HI_W        "\033[0;97m\001"

// Bold high intensity
# define C_B_HI_BL    "\033[1;90m\001"
# define C_B_HI_R    "\033[1;91m\001"
# define C_B_HI_G    "\033[1;92m\001"
# define C_B_HI_Y    "\033[1;93m\001"
# define C_B_HI_B    "\033[1;94m\001"
# define C_B_HI_P    "\033[1;95m\001"
# define C_B_HI_C    "\033[1;96m\001"
# define C_B_HI_W    "\033[1;97m\001"

// Background high intensity
# define C_BG_HI_BL    "\033[0;100m\001"
# define C_BG_HI_R    "\033[0;101m\001"
# define C_BG_HI_G    "\033[0;102m\001"
# define C_BG_HI_Y    "\033[0;103m\001"
# define C_BG_HI_B    "\033[0;104m\001"
# define C_BG_HI_P    "\033[0;105m\001"
# define C_BG_HI_C    "\033[0;106m\001"
# define C_BG_HI_W    "\033[0;107m\001"

// Reset
# define C_RST        "\033[0m\002"

#endif
