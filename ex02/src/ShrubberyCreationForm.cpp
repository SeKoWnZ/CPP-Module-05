/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:09:04 by jose-gon          #+#    #+#             */
/*   Updated: 2025/06/11 12:44:24 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ShrubberyCreationForm.hpp>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyForm", 145, 137), _target(target)
{	
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& source) : AForm(source), _target(source._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& source)
{
	if (this != &source)
		AForm::operator=(source);
	return *this;
}

void ShrubberyCreationForm::runForm() const
{
	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file.is_open())
	{
		std::cout << "Erro: File can't be open" << std::endl;
		return;
	}
	std::cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	std::cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMNKOk0KNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	std::cout << "MMMMMMMMMMMMMMMMMMMMMMMMWXklccccdKWMMMMMMWWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	std::cout << "MMMMMMMMMMMMMMMMMMMMMMMNOdlllllcco0WMMWX0xlxXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	std::cout << "MMMMMMMMMMMMMMMMMMMMMMWKo:::::clllxNWKxc;,',l0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	std::cout << "MMMMMMMMMMMMMMMMMMMMMN0xlc:;;;:clllxk:'''''''cONMMMMMMMMMMMMMMMMMMWWMMMMMMMMMMMM" << std::endl;
	std::cout << "MMMMMMMMMMMMMMMMMMMMW0olllllxOo:::ccc,,;;,'''';dXMMMMMMMMMMMMMMMWK0NMMMMMMMMMMMM" << std::endl;
	std::cout << "MMMMMMMMMMMMMMMMMMWN0xxkxdOO0Ko:cc:;;:c:;,''',,,xNMMMMMMMMMMMMWW0ldXWMMMMMMMMMMM" << std::endl;
	std::cout << "MMMMMMMMMMMMMMMMMW0dlcloolookN0dl:,'',,;;;;;''''oXMMMMMMMMMMMW0xl;cxXWMMMMMMMMMM" << std::endl;
	std::cout << "MMMMMMMMXKNMMMMMMKdlc:::cdOkx0Okd:::,'',,,;;:;',:xKWMMMMMMXKWN0xl;:dXWMMMMMMMMMM" << std::endl;
	std::cout << "MMMMMMMWkckWMMMMMWKOdccccokkoooolcllc::;,,::;,'',;oXMMMMNOccOXko:,,:xXWMMMMMMMMM" << std::endl;
	std::cout << "MMMMMMMKl,c0MMMMWX0ko:;;colccc::,,;:lll:;;,''',:dOXWMMMWO:.'ckdc;,,;dKWMMMMMMMMM" << std::endl;
	std::cout << "MMMMMMWk;',xNMMWOolc:;:llolc:::::;:;;;:::;cllllkNMMMMMMXd;..,cc;,,,;dKWMMMMMMMMM" << std::endl;
	std::cout << "MMMMMNx:'.'lKWMW0xxdoddO0kxxoloclxocllodoco0XNWWMMMMMMWKc'..',;,',,,;cd0WMMMMMMM" << std::endl;
	std::cout << "MMMMMXd;'..,xNMMMWNkodkkdkKKkl;:dkkxooxdocl0MMMMMMMMMWKd:'.'',;;,,,,lxOXWMMMMMMM" << std::endl;
	std::cout << "MMMMMXd;'..'lKWMMMW0dddo::lol:,:lldxdkKklcc0MMMMMMMMMXkl;'.'',;;,,,,:ox0NMMMMMMM" << std::endl;
	std::cout << "MMMWXx;....':kNNKOxocccc:;clc;,;:cllllollccxKKXNWWMMWKo;'....',,,,,,,,cONMMMMMMM" << std::endl;
	std::cout << "MMMNOc'.'''';okkxdolccc::;:c:;,;ccllllcccccccllddxOOxl;''..''',,,,,,,,:xKNMMMMMM" << std::endl;
	std::cout << "MMWXOdllllc:cllooolcccc::;:cc:loolccccccccccccccccccccc:,'''',,,,,,,,;::ckXWMMMM" << std::endl;
	std::cout << "WN0xdxxddddddddxxxkkkkOO00KK000000OOOkkkkkkkxxxxxdddxxkkxxdollcccllldxkxxxk0KNMM" << std::endl;
	std::cout << "WNXXKXXXXXNNNNWWWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWWWWNNNNNNNNNXXXXXXXNNNNNNNNNWMM" << std::endl;
	file.close();
}
