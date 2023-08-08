# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    flatten.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 20:05:13 by kiroussa          #+#    #+#              #
#    Updated: 2023/08/08 20:56:04 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Flattens the repository as to create a libft that's suitable for evaluation.
# NOTE: this does *NOT* remove extra functions.

# Ask the user if they're sure about running this script

read -p "Are you sure you want to flatten this project? [y/N] " -n 1 -r
echo

if [[ ! $REPLY =~ ^[Yy]$ ]]
then
	exit 1
fi

# Copy all .c files in src/ into the source root, as well as all headers in include/
# This is useful for the moulinette

find src/ -type f -name "*.c" -exec cp {} . \;
find include/ -type f -name "*.h" -exec cp {} . \;

SUBFOLDERS=$(find src/ -type d -not -path "src/" | sed 's/^src\///g')

rm -rf src/ include/

sed -i 's/src/\./g' Makefile
sed -i 's/include/\./g' Makefile

for SUBFOLDER in $SUBFOLDERS
do
	sed -i "s/$SUBFOLDER\///g" Makefile
done

rm README.md
rm .gitignore
rm flatten.sh
