import sys

with open (sys.argv[1], 'r') as f:
	for line in f:
		n, m = [int(x) for x in line.split()]

		if (m == 1):
			print (n - 1)
		elif (m == 0):
			print (n)

		# excluding the last door and iteration from calculations, the state of the last door is computed at the end and added if open
		n_exclude_last = n - 1
		m_exclude_last = m - 1

		# ax represents number of doors affected by beat 1
		# bx represents number of doors affected by beat 2
		# abx represents number of doors affected by both
		# always_open represents number of doors affected by neither
		ax = n_exclude_last // 2
		bx = n_exclude_last // 3
		abx = n_exclude_last // 6
		always_open = n_exclude_last - ax - (bx - abx)

		# o represents number of doors that will always be open regardless of number of iterations > 1
		o = abx + always_open

		if m_exclude_last > 1 and m_exclude_last % 2 == 0:
			o += bx - abx

			if n % 3 != 0 and n % 2 == 0:
				o += 1
		elif n % 3 == 0 and n % 2 != 0:
			o += 1
		elif n % 3 != 0 and n % 2 == 0:
			o += 1

		print (o)