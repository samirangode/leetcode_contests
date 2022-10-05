def main():
  test_cases = int(input())
  for test_case in range(1, test_cases + 1):
    N, Q = map(int, input().split())
    blocks = input()
    questions = []
    for i in range(Q):
      L, R = map(int, input().split())
      questions.append((L, R))

    answer = count_yes(N, Q, blocks, questions)

    print(f'Case #{test_case}: {answer}')


def count_yes(N, Q, blocks, questions):
  # TODO: Complete this function and return the number of "yes" answers.
  yes_answers = 0

  return yes_answers

if __name__ == '__main__':
  main()
