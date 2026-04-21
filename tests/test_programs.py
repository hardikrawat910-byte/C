import re
import subprocess
import tempfile
import unittest
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[1]


def compile_c(source: str, output: Path, extra_flags=None):
    cmd = ["gcc", str(REPO_ROOT / source), "-o", str(output)]
    if extra_flags:
        cmd.extend(extra_flags)
    return subprocess.run(cmd, capture_output=True, text=True)


def run_program(executable: Path, program_input: str, timeout: int = 2):
    return subprocess.run(
        [str(executable)],
        input=program_input,
        capture_output=True,
        text=True,
        timeout=timeout,
        check=False,
    )


class ProgramBehaviorTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.temp_dir = tempfile.TemporaryDirectory()
        cls.bin_dir = Path(cls.temp_dir.name)

    @classmethod
    def tearDownClass(cls):
        cls.temp_dir.cleanup()

    def build_ok(self, source: str, extra_flags=None) -> Path:
        exe = self.bin_dir / (Path(source).stem + ".out")
        result = compile_c(source, exe, extra_flags=extra_flags)
        self.assertEqual(result.returncode, 0, msg=result.stderr)
        return exe

    def test_hello_output(self):
        exe = self.build_ok("Basic/hello.c")
        result = run_program(exe, "")
        self.assertIn("Hello this is my first program in linux", result.stdout)
        self.assertIn("And hello to this world", result.stdout)

    def test_largest_number_branches(self):
        exe = self.build_ok("Basic/largestnum.c")
        a = run_program(exe, "9 2 1\n")
        b = run_program(exe, "2 9 1\n")
        c = run_program(exe, "2 1 9\n")
        self.assertIn("9 is largest", a.stdout)
        self.assertIn("9 is largest", b.stdout)
        self.assertIn("9 is largest", c.stdout)

    def test_reverse_number(self):
        exe = self.build_ok("Basic/reversenum.c")
        result = run_program(exe, "1234\n")
        self.assertIn("Your reversed number is 4321", result.stdout)

    def test_swap_with_temp(self):
        exe = self.build_ok("Basic/swappingnumber.c")
        result = run_program(exe, "2 5\n")
        self.assertIn("a is 5 and b is 2", result.stdout)

    def test_swap_without_temp(self):
        exe = self.build_ok("Basic/swappingnum.c")
        result = run_program(exe, "2 5\n")
        self.assertIn("first digit after swapping is 5", result.stdout)
        self.assertIn("second digit after swapping is 2", result.stdout)

    def test_compound_interest(self):
        exe = self.build_ok("Basic/compundint.c", extra_flags=["-lm"])
        result = run_program(exe, "1000\n10\n2\n")
        self.assertIn("The compund intrest is", result.stdout)
        self.assertRegex(result.stdout, r"210\.0+")

    def test_factorial_iterative_and_recursive(self):
        exe = self.build_ok("Numbers/factorial.c")
        result = run_program(exe, "5\n")
        self.assertIn("using interative is 120", result.stdout)
        self.assertIn("using recursive is 120", result.stdout)

    def test_factorial_zero(self):
        exe = self.build_ok("Numbers/factorial.c")
        result = run_program(exe, "0\n")
        self.assertIn("using interative is 1", result.stdout)
        self.assertIn("using recursive is 1", result.stdout)

    def test_fibonacci_progression(self):
        exe = self.build_ok("Numbers/fibonacci.c")
        result = run_program(exe, "5\n")
        numbers = re.findall(r"\b\d+\b", result.stdout)
        self.assertTrue({"0", "1", "2", "3"}.issubset(set(numbers)))

    def test_leap_year_true_and_false(self):
        exe = self.build_ok("Numbers/leapyear.c")
        leap = run_program(exe, "2000\n")
        not_leap = run_program(exe, "1900\n")
        self.assertIn("leap year", leap.stdout)
        self.assertIn("not a leap year", not_leap.stdout)

    def test_palindrome_true_and_false(self):
        exe = self.build_ok("Numbers/palindrome.c")
        pal = run_program(exe, "121\n")
        not_pal = run_program(exe, "123\n")
        self.assertIn("121 is palindrome", pal.stdout)
        self.assertIn("123 is not palindrome", not_pal.stdout)

    def test_prime_number_true_and_false(self):
        exe = self.build_ok("Numbers/primenum.c")
        prime = run_program(exe, "2\n")
        not_prime = run_program(exe, "9\n")
        one = run_program(exe, "1\n")
        self.assertIn("2 is prime number", prime.stdout)
        self.assertIn("9 is not prime number", not_prime.stdout)
        self.assertIn("1 is not prime number", one.stdout)

    def test_second_largest(self):
        exe = self.build_ok("Numbers/secondlar.c")
        result = run_program(exe, "4\n1 7 3 8 0\n")
        self.assertIn("The second largest number is 7", result.stdout)

    def test_array_sum(self):
        exe = self.build_ok("array/arraysum.c")
        result = run_program(exe, "3\n1 2 3 0\n")
        self.assertIn("The sum is 6", result.stdout)

    def test_armstrong_zero_path(self):
        exe = self.build_ok("Numbers/armstrong.c")
        result = run_program(exe, "0\n")
        self.assertIn("0 is Armstrong number", result.stdout)

    def test_armstrong_nonzero_currently_times_out(self):
        exe = self.build_ok("Numbers/armstrong.c")
        with self.assertRaises(subprocess.TimeoutExpired):
            run_program(exe, "153\n", timeout=1)

    def test_even_odd_fails_to_compile_on_linux(self):
        result = compile_c("Basic/even_odd.c", self.bin_dir / "even_odd.out")
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("clrscr", result.stderr)

    def test_prog1_fails_to_compile_on_linux(self):
        result = compile_c("Numbers/prog1.c", self.bin_dir / "prog1.out")
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("conio.h", result.stderr)


if __name__ == "__main__":
    unittest.main()
