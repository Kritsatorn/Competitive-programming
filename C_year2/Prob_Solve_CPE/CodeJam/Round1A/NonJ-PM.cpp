#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::size_t T;
    cin >> T;

    for (auto t = 0; t < T; ++t) {

        std::size_t N;
        cin >> N;

        vector<string> middle_blocks;

        string begin_string;
        string end_string;

        bool flag_impossible = false;

        for (auto n = 0; n < N; ++n) {
            string input;
            cin >> input;

            string block;
            std::size_t block_ctr = 0;

            for (const auto& ch : input) {
                if (ch == '*') {
                    // Flush block
                    if (block_ctr == 0) {
                        // Begin block compute
                        for (auto i = 0; i < block.size(); ++i) {
                            if (i < begin_string.size()) {
                                if (begin_string[i] != block[i]) {
                                    flag_impossible = true;
                                }
                            } else {
                                begin_string.push_back(block[i]);
                            }
                        }
                    } else {
                        // Middle block compute
                        middle_blocks.push_back(block);
                    }

                    block.clear();
                    block_ctr++;
                } else {
                    // Add to block
                    block.push_back(ch);
                }
            }

            // Final block compute
            for (auto i = 0; i < block.size(); ++i) {
                if (i < end_string.size()) {
                    if (end_string[i] != block[block.size() - i - 1]) {
                        flag_impossible = true;
                    }
                } else {
                    end_string.push_back(block[block.size() - i - 1]);
                }
            }
        }

        string result_string = begin_string;
        for (const auto& middle_block:middle_blocks) {
            result_string.append(middle_block);
        }
        reverse(end_string.begin(), end_string.end());
        result_string.append(end_string.begin(), end_string.end());

        if (result_string.empty()) {
            result_string = "ABC";
        }

        if (flag_impossible) {
            cout << "Case #" << t + 1 << ": *\n";
        } else {
            cout << "Case #" << t + 1 << ": " << result_string << '\n';
        }

    }

    return 0;
}