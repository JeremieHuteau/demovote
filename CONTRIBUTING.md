This project follows the Test Driven Development cycle:

 - write a test
 - run all tests (new test should fail)
 - write code to make the test pass
 - run all tests (new test should pass)
 - refactor the code

We follow [this branching model](https://nvie.com/posts/a-successful-git-branching-model/):

 - branch from `dev` (name your branch according to the feature you are implementing)
 - commit self-contained, test passing code
 - pull from `dev` often to avoid the pain of resolving a lot of merge conflicts
 - pull request to `dev` when your feature is ready
