/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	ball(Ball(Vec2(Graphics::ScreenWidth / 2, Graphics::ScreenHeight / 2), Vec2(300.0f, 300.0f), Colors::Cyan, 8)),
	bounds(0, 0, Graphics::ScreenWidth, Graphics::ScreenHeight)
{
	Color blockColors[4] = {Colors::Red, Colors::Green, Colors::Blue, Colors::Yellow};

	for(int y = 0; y < nBlocksY; y++)
	{
		Color color = blockColors[y % 4];
		for(int x = 0; x < nBlocksX; x++)
		{
			Vec2 topLeft = Vec2(x * blockWidth + blockOffset, y * blockHeight + blockOffset);
			Rect rect = Rect(topLeft, blockWidth, blockHeight);
			blocks[(y * int(blockHeight)) + x] = Block(rect, color);
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	float deltaTime = frameTimer.Mark();
	ball.Move(deltaTime, bounds);
}

void Game::DrawBlocks()
{
	for(auto& block : blocks)
	{
		block.Draw(gfx);
	}
}

void Game::ComposeFrame()
{
	ball.Draw(gfx);
	DrawBlocks();
}
