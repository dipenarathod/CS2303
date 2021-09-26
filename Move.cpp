int right = 0, left = 0, up = 0;
	//check if can jump
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++) {
			if (theBoard->getEdge(i,j) == 'b') {
				up = i - 1; right = j + 1; left = j - 1;
				if (up >= 0)
				{
					if (right >= 1 && right <= 8) {
						if (theBoard->getEdge(up,right) == 'r')
						{
							up -= 1;
							right += 1;
							if (up >= 0 && right >= 1 && right <= 8)
							{
								if(theBoard->getEdge(up, right) == '-'){
								theBoard->setEdge(up, right, 'b');
								theBoard->setEdge((up+1), (right-1), '-');
								theBoard->setEdge(i,j,'-');
								}
							}
						}
					} // End if right
					if (left >= 0 && left <= 7)
					{
						if (theBoard->getEdge(up,left) == 'r')
						{
							up -= 1;
							left -= 1;
							if (up >= 0 && left >= 0 && left <= 7)
							{
								puts("Can jump on left");
								if(theBoard->getEdge(up, left) == '-'){
									theBoard->setEdge(up, left, 'b');
									theBoard->setEdge((up+1),(left+1),'-');
									theBoard->setEdge(i,j,'-');
								}

							}
						}
					} // End if left
				}// End if up
			} // End if b
		} // End for col
	} // End for row