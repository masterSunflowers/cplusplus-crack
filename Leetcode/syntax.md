# Some essential standard built-in function in c++

<details>
    <summary>vector</summary>

- Find max/min element in vector

    ```cpp
    max_value = *max_element(vect);
    max_value_idx = max_element(vect) - vect.begin();
    min_value = *min_element(vect);
    min_value_idx = min_element(vect) - vect.begin();
    ```

- Custom compare behaviour (change sort function)

    ```cpp
    bool cmp(const pair<int, int> &a, const pair<int, int> &b);
    sort(vect.begin(), vect.end(), cmp);
    ```

</details>

<details>
    <summary>queue</summary>

</details>

<details>
    <summary>set/unordered_set</summary>

- `unordered_set` hash value of key => Insert item to `unordered_set` O(1), keys aren't sorted

- `set` build upon binary search tree => Insert item to `set` O(`h`) where `h` is the height of tree, keys are sorted

</details>

<details>
    <summary>map/unordered_map</summary>
</details>

<details>
    <summary>bitset</summary>

- Store bits (usually is binary representation of a number)

- Support some function to manipulate with bits like `count`, `any`, `set`(set bit to 1), `reset`(set bit to 0), `flip`

</details>