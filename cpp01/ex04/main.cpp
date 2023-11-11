/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:04:40 by cahn              #+#    #+#             */
/*   Updated: 2023/11/11 20:36:32 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    std::ifstream is;
    std::ofstream os;
    
    if (argc != 4)
    {
        std::cout << "argument error\n";
        return 1;
    }

    std::string s1(argv[2]);
    std::string s2(argv[3]);
    if (s1.length() == 0 || s2.length() == 0 || argv[1][0] == 0)
    {
        std::cout << "argument error\n";
        return 1;
    }
    is.open(argv[1]);
    if (is.fail())
    {
        std::cout << "Can't Open input file\n";
        return 1;
    }
    std::string outfile(argv[1]);
    outfile.append(".replace");
    os.open(outfile);
    if (os.fail())
    {
        std::cout << "Can't Open output file\n";
        return 1;
    }
    
    std::string tmp;
    while (1)
    {
        getline(is, tmp);
        size_t loc;
        while (1)
        {
            loc = tmp.find(s1);
            if (loc == std::string::npos)
                break;
            tmp.erase(loc, s1.length());
            tmp.insert(loc, s2);
        }
        os << tmp;
        if (is.eof())
            break;
        os << std::endl;
    }
}