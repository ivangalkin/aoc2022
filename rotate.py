USAGE = 'Run as `rotate.py infile outfile degrees`'

import sys
try:
    from itertools import zip_longest
except ImportError:
    from itertools import izip_longest as zip_longest


def transpose(instream, rotate=False):
	"""Transposes strings."""
	stripped = [l.rstrip() for l in instream.split('\n')]
	transposed = map(''.join, zip_longest(*stripped, fillvalue=' '))
	if rotate:
		transposed = reversed(list(transposed))
	return '\n'.join(transposed)


def mirror(instream, vertical=False):
	"""Mirrors strings (horizontally by default)."""
	if vertical:
		# Can preserve trailing whitespace
		unstripped = instream.split('\n')
		mirrored = reversed(unstripped)
	else:
		# Relies on padding => needs a strip
		stripped = [l.rstrip() for l in instream.split('\n')]
		maxlen = max(len(l) for l in stripped)
		padded = [l.ljust(maxlen) for l in stripped]
		mirrored = [l[::-1] for l in padded]
	return '\n'.join(mirrored)


def rotate(instream):
	"""Rotates strings by 90 degrees, counterclockwise."""
	return transpose(instream, rotate=True)


def main(infile, outfile, iterations):
	"""Rotates strings by `iterations` * 90 degrees, counterclockwise,
	and writes the result to `outfile`.
	While certain degrees like multiples of 45 might be fun to implement,
	this only works with multiples of 90 for the time being."""
	with open(infile, 'r') as f:
		f = ''.join(line for line in f)
	for _ in range(iterations):
		f = rotate(f)
	with open(outfile, 'w') as out:
		out.write(f)


if __name__ == '__main__':
	if len(sys.argv) < 2 or len(sys.argv) > 4:
		print(USAGE)
		sys.exit(1)

	import doctest
	doctest.testmod()
	infile, outfile, rotation = sys.argv[1:]
	# how often to rotate 90 degrees, counterclockwise
	iterations = int(rotation) // 90
	main(infile, outfile, iterations)
	print(outfile)